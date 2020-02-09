
/*
 * PS4Delta : PS4 emulation and research project
 *
 * Copyright 2019-2020 Force67.
 * For information regarding licensing see LICENSE
 * in the root of the source tree.
 */

#include <base.h>

#include "kern/dev/console_dev.h"
#include "kern/dev/dipsw_dev.h"
#include "kern/dev/dma_dev.h"
#include "kern/dev/gc_dev.h"
#include "kern/dev/tty6_dev.h"
#include "kern/process.h"

#include <utl/object_ref.h>

namespace kern {
static device* make_device(const char* deviceName) {
    std::string_view xname(deviceName);

    device* dev = nullptr;
    auto* proc = process::getActive();
    if (xname == "console")
        dev = new consoleDevice(proc);
    if (xname == "deci_tty6")
        dev = new tty6Device(proc);
    if (xname == "gc")
        dev = new gcDevice(proc);
    if (xname == "dipsw")
        dev = new dipswDevice(proc);
    /*there are multiple of these*/
    if (xname.find("dmem") != -1)
        dev = new dmaDevice(proc);

    return dev;
}

int PS4ABI sys_open(const char* path, uint32_t flags, uint32_t mode) {
    if (!path)
        return SysError::eINVAL;

    std::printf("open: %s, %x, %x\n", path, flags, mode);

    if (std::strncmp(path, "/dev/", 5) == 0) {
        const char* name = &path[5];

        auto dev = make_device(name);
        if (dev) {

            if (!dev->init(name, flags, mode)) {
                dev->releaseHandle();
                return -1;
            }

            return dev->handle();
        } else
            dbg_break();
        return -1;
    }

    dbg_break();
    return 0;
}

int PS4ABI sys_close(uint32_t fd) {
    auto* proc = process::getActive();

    if (proc && fd != -1) {
        proc->ids().release(fd);
        return 0;
    }

    LOG_WARNING("failed to release handle {}", fd);
    return -1;
}
} // namespace krnl