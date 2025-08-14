#pragma once

#include "revolution.h"

class BinaryDataContentHeaderSerializer {
public:
    BinaryDataContentHeaderSerializer(u8 *, u32);

    void addAttribute(const char *, u32);
    void flush();
    u32 getHeaderSize() const;
    u32 getDataSize() const;

    u8 _0[0x1C];
};