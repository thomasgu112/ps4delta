
// Copyright (C) Force67 2019

#ifdef __linux__
#include <cstddef>
#include "mem.h"
#include <map>
#include <unistd.h>
#include <sys/mman.h>

namespace utl {
    std::map<void*, size_t> memRegionSize;

    void* allocMem(void* preferredAddr, size_t length, page_protection prot, allocType type) {
        if(type == allocType::commit) {
            mprotect(preferredAddr, length, (uint32_t) prot);
            return preferredAddr;
        }
        else if(type == allocType::reserve)
            prot = page_protection::page_private;
        void* mem;
        mem = mmap(preferredAddr, length, (uint32_t) prot, MAP_SHARED | MAP_ANON, -1, 0);
        memRegionSize.insert(std::pair<void*, size_t> (mem, length));
        return mem;
    }

    void freeMem(void* Addr) {
        munmap(Addr, memRegionSize[Addr]);
        memRegionSize.erase(Addr);
    }

    bool protectMem(void* addr, size_t len, page_protection prot) {
        return mprotect(addr, len, (uint32_t) prot) == 0;
    }

    size_t getAvailableMem()
    {
        return sysconf(_SC_PAGESIZE)*sysconf(_SC_PHYS_PAGES);
    }
}
#endif
