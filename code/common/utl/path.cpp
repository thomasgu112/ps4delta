
/*
 * UTL : The universal utility library
 *
 * Copyright 2019-2020 Force67.
 * For information regarding licensing see LICENSE
 * in the root of the source tree.
 */

#include <algorithm>

#include "path.h"
#include "string_util.h"

#ifdef _WIN32
#include <Windows.h>
#include <shlobj.h> // for SHGetFolderPath
#endif

#ifdef __linux__
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

#include "logger/logger.h"

namespace utl {
#ifdef _WIN32
std::string make_abs_path(std::string_view rel) {
    static std::string filePath;
    if (filePath.empty()) {
        wchar_t buf[2048]{};

        GetModuleFileNameW(nullptr, buf, 2048);
        wchar_t* dirPtr = std::wcsrchr(buf, L'\\');
        dirPtr[1] = L'\0';

        filePath = utl::utf16_to_utf8(buf);
    }

    auto newPath = rel.empty() ? filePath : filePath + rel.data();

    // sanitize the path (this is a windows thing, on linux & osx we
    // need to do it the other way around)
    std::replace(newPath.begin(), newPath.end(), '/', '\\');

    return newPath;
}

static std::string get_home_dir() {
    PWSTR localPath = nullptr;
    if (FAILED(SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &localPath)))
        dbg_break();
    auto newPath = utl::utf16_to_utf8(localPath);
    CoTaskMemFree(localPath);
    return newPath;
}

bool exists(std::string_view rel) {
    if (rel.empty())
        return false;

    auto newPath = utl::utf8_to_utf16_w(std::string(rel));
    return GetFileAttributesW(newPath.c_str()) != INVALID_FILE_ATTRIBUTES;
}

bool make_dir(std::string_view rel) {
    if (rel.empty())
        return false;

    auto newPath = utl::utf8_to_utf16_w(std::string(rel));

    // allows for recursive directory creation
    return SHCreateDirectoryEx(nullptr, newPath.c_str(), nullptr);
}

std::string make_app_path(app_path path, std::string_view rel /* = nullptr */) {
    static std::string filePaths[app_path::count];

    if (filePaths[path].empty()) {
        auto& newPath = filePaths[path];

        switch (path) {
        case app_path::data_dir: {

            // TODO: change backslashes
            newPath = get_home_dir() + "\\" + FXNAME + "\\";
            if (!exists(newPath))
                make_dir(newPath);

            return rel.empty() ? newPath : newPath + rel.data();
        }
        default:
            return make_abs_path(rel);
        }
    }

    return rel.empty() ? filePaths[path] : filePaths[path] + rel.data();
}

#elif __linux__
std::string make_abs_path(std::string_view rel) {
    static std::string filePath;
    if (filePath.empty()) {
        char buf[2048]{};

        readlink("/proc/self/exe", buf, 2048);
        char* dirPtr = std::strrchr(buf, '/');
        dirPtr[1] = '\0';

        filePath = buf;
    }

    auto newPath = rel.empty() ? filePath : filePath + rel.data();
    return newPath;
}

static std::string get_home_dir() {
    std::string path = getenv("HOME");
    path += "/.config/ps4delta";
    return path;
}

bool exists(std::string_view rel) {
    return access(std::string(rel).c_str(), F_OK) == 0;
}

bool make_dir(std::string_view rel) {
    if (rel.empty())
        return false;

    auto newPath = std::string(rel);
    int lastSlash = -1;
    while(lastSlash < newPath.length()) {
        lastSlash = newPath.find(lastSlash + 1, '/');
        if(mkdir(newPath.substr(0, lastSlash).c_str(), 777) != 0)
            return false;
    }

    return true;
}

std::string make_app_path(app_path path, std::string_view rel /* = nullptr */) {
    static std::string filePaths[app_path::count];

    if (filePaths[path].empty()) {
        auto& newPath = filePaths[path];

        switch (path) {
        case app_path::data_dir: {

            // TODO: change backslashes
            newPath = get_home_dir() + "/" + FXNAME + "/";
            if (!exists(newPath))
                make_dir(newPath);

            return rel.empty() ? newPath : newPath + rel.data();
        }
        default:
            return make_abs_path(rel);
        }
    }

    return rel.empty() ? filePaths[path] : filePaths[path] + rel.data();
}
} // namespace utl

#endif