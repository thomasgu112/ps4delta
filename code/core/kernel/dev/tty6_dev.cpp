
// Copyright (C) Force67 2019

#include "tty6_dev.h"

namespace kern {
tty6Device::tty6Device(process* p) : device(p) {}

bool tty6Device::init(const char*, uint32_t, uint32_t) {
    return true;
}

uint8_t* tty6Device::map(void* addr, size_t, uint32_t, uint32_t, size_t) {
    dbg_break();
    return reinterpret_cast<uint8_t*>(-1);
    // return SysError::SUCCESS;
}
} // namespace krnl