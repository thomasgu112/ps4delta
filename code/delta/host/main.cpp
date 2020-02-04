
// Copyright (C) 2019 Force67

#ifdef _WIN32

#include <Windows.h>

// windows platform init
int main(int argc, char **argv) {
  auto *hlib = LoadLibraryW(L"dcore.dll");
  if (!hlib) {
    MessageBoxW(0, L"Unable to load core", FXNAME_WIDE, 0);
    return -1;
  }

  auto corMain = (int (*)(int, char **))GetProcAddress(hlib, "dcoreMain");
  if (corMain)
    return corMain(argc, argv);

  return -1;
}
#else

#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char **argv) {
  auto *hlib = dlopen("dcore.so", RTLD_LAZY);
  if (!hlib) {
    fprintf(stderr, "Unable to load core: %s\n", dlerror());
    return -1;
  }

  auto corMain = (int (*)(int, char **))dlsym(hlib, "dcoreMain");
  if (corMain)
    return corMain(argc, argv);

  return -1;
}
#endif
