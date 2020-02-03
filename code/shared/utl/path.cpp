
/*
 * UTL : The universal utility library
 *
 * Copyright 2019-2020 Force67.
 * For information regarding licensing see LICENSE
 * in the root of the source tree.
 */

#include <algorithm>
#ifdef _WIN32
#include <Windows.h>
#else
#include <base.h>
#include <unistd.h>
#endif
#include <utl/path.h>

namespace utl {
#ifdef _WIN32
std::wstring make_abs_path(const std::wstring &rel) {
  static std::wstring filePath;
  if (filePath.empty()) {
    wchar_t buf[MAX_PATH]{};

    GetModuleFileNameW(nullptr, buf, MAX_PATH);
    wchar_t *dirPtr = std::wcsrchr(buf, L'\\');
    dirPtr[1] = L'\0';

    filePath = buf;
  }

  auto newPath = filePath + rel;

  // sanitize the path (this is a windows thing, on linux & osx we
  // need to do it the other way around)
  std::replace(newPath.begin(), newPath.end(), L'/', L'\\');

  return newPath;
}
#endif

std::string make_abs_path(const std::string &rel) {
  static std::string filePath;
  if (filePath.empty()) {
    char buf[MAX_PATH]{};

    #ifdef _WIN32
    GetModuleFileNameA(nullptr, buf, MAX_PATH);
    char *dirPtr = std::strrchr(buf, '\\');
    dirPtr[1] = '\0';
    #else
    ssize_t size = ::readlink("/proc/self/exe", buf, MAX_PATH - 1);
    if (size != -1) buf[size] = '\0';
    #endif

    filePath = buf;
  }

  auto newPath = filePath + rel;

  // sanitize the path (this is a windows thing, on linux & osx we
  // need to do it the other way around)
  #ifdef _WIN32
  std::replace(newPath.begin(), newPath.end(), '/', '\\');
  #else
  std::replace(newPath.begin(), newPath.end(), '\\', '/');
  #endif

  return newPath;
}

} // namespace utl