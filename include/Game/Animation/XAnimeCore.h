#pragma once

#include "JSystem/JGeometry/TVec.h"




class XjointTransform {
public:
    XjointTransform();

    void setLocalScale(f32 scale) {
        mScale.set(scale);
    };

    /* 0x00 */ u32 _0;
    /* 0x04 */ s16 _4;
    /* 0x08 */ TVec3f mScale;
    /* 0x14 */ TVec3f _14;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ TVec3f _2C;
    /* 0x38 */ TVec3f _38;
    /* 0x44 */ f32 _44;
    /* 0x48 */ f32 _48;
    /* 0x4C */ f32 _4C;
    /* 0x50 */ u16 _50;
    /* 0x52 */ u16 _52;
    /* 0x54 */ u16 _54;
    /* 0x56 */ u16 _56;
    /* 0x58 */ f32 _58;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ f32 _60;
    /* 0x64 */ MtxPtr _64;
    /* 0x68 */ u32 _68;
    /* 0x6C */ MtxPtr _6C;
};