
/*
 * PS4Delta : PS4 emulation and research project
 *
 * Copyright 2019-2020 Force67.
 * For information regarding licensing see LICENSE
 * in the root of the source tree.
 */

#include <cstdio>
#include <thread>

#include <QCommandLineParser>

#include "dcore.h"
#include <logger/logger.h>
#include <utl/file.h>

#include "formats/pup_object.h"

deltaCore::deltaCore(int &argc, char **argv) : QApplication(argc, argv) {
  setApplicationName(rsc_productname);
  setApplicationVersion(rsc_productversion);
}

bool deltaCore::init() {
  LOG_INFO("Initializing deltaCore " rsc_copyright);

  if (!headless)
    window = std::make_unique<mainWindow>(*this);

  if (window)
    window->init();

  return true;
}

void deltaCore::boot(std::string &xdir) {
  static std::string dir = xdir;

  // sanitize path
  std::replace(dir.begin(), dir.end(), '/', '\\');

  std::thread ctx([&]() {
    auto proc = std::make_unique<krnl::proc>();
    if (!proc->create(dir))
      return;

    proc->start();
  });

  ctx.detach();
}