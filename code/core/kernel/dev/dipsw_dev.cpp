
/*
 * PS4Delta : PS4 emulation and research project
 *
 * Copyright 2019-2020 Force67.
 * For information regarding licensing see LICENSE
 * in the root of the source tree.
 */

#include "dipsw_dev.h"

namespace kern {
dipswDevice::dipswDevice(process* p) : device(p) {}

/* dipsw_dev_ioctl */
int32_t dipswDevice::ioctl(uint32_t cmd, void* data) {
    switch (cmd) {
    case 0x40048806: /*sceKernelCheckDipsw*/
        *static_cast<uint32_t*>(data) = 1;
        break;
    /* dont seem to be implemented ? */
    case 0x40048807:
    case 0x40088808:
    case 0x40088809:
        *static_cast<uint32_t*>(data) = 0;
        break;
    default:
        dbg_break();
    }

    return 0;
}
} // namespace krnl