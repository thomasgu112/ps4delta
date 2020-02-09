#pragma once

// Copyright (C) Force67 2019

#include "device.h"

namespace kern {
class tty6Device : public device {
public:
    tty6Device(process*);

    bool init(const char*, uint32_t, uint32_t) override;
    uint8_t* map(void*, size_t, uint32_t, uint32_t, size_t) override;
};
}