#pragma once

#include "revolution.h"
#include "JSystem/JGeometry.h"

class DpdInfo {
public:
    DpdInfo();

    TVec2f _0;
    u8 _8;
    u8 _9;
    u32 _C;
    f32 mViewDistZ;     // 0x10
};

class StarPointerController {
public:
    StarPointerController();

    s32 mPort;          // 0x0
    DpdInfo _4;
    DpdInfo _18;
    TVec2f _2C;
    u32 _34;
    u32 _38;
    u32 _3C;
    u32 _40;
    u32 _44;
    u32 _48;
    u32 _4C;
    TVec2f _50;
    TVec2f _58;
    TVec3f _60;
    TVec3f _6C;
    u8 _78;
};