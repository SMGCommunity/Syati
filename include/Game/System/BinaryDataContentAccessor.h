#pragma once

#include "revolution.h"

class BinaryDataContentAccessor {
public:
    BinaryDataContentAccessor(u8 *);

    u32 getHeaderSize() const;
    u32 getDataSize() const;
    void* getPointer(const char *, u8 *) const;
};