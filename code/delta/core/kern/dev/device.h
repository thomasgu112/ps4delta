#pragma once

// Copyright (C) Force67 2019

#include <base.h>
#include "kern/lv2/error_table.h"
#include "kern/object.h"

namespace krnl {
class proc;

class device : public kObject {
public:
  inline device(proc *p) : kObject(p, kObject::oType::device) {}

  virtual bool init(const char *, uint32_t, uint32_t) { return true; }
  virtual uint8_t *map(void *, size_t, uint32_t, uint32_t, size_t) {
    dbg_break();
    return nullptr;
  }
  virtual int32_t ioctl(uint32_t command, void *args) {
    dbg_break();
    return -1;
  }
};
}