#pragma once

#include "syati.h"

class MarioAnimator {
public:
    MarioAnimator(MarioActor *);

    MarioActor *mMarioActor; // _0
    XanimeResourceTable *mResourceTable; // _4
    XanimePlayer *mXanimePlayer; // _8
    XanimePlayer *mXanimePlayerUpper; // _C
    XanimePlayer *_10;
    u8 _14;
    u8 _15;
    u8 _16;
    u8 _17;
    f32 _18;
    f32 _1C;
    f32 _20;
    f32 _24;
    MtxPtr _28;
    u32 _2C;
    u32 _30;
    u32 _34;
    u32 _38;
    u32 _3C;
    u32 _40;
    u32 _44;
    u32 _48;
    u32 _4C;
    u32 _50;
    u32 _54;
    f32 _58;
    f32 _5C;
    TVec3f _60;
    u8 _6C;
    u8 _6D;
    u8 _6E;
    u8 _6F;
    f32 _70;
    u32 _74;
    u16 _78;
    u16 _7A;
    MtxPtr _7C;
    u32 _80;
    u32 _84;
    u32 _88;
    u32 _8C;
    u32 _90;
    u32 _94;
    u32 _98;
    u32 _9C;
    u32 _A0;
    u32 _A4;
    u32 _A8;
    MtxPtr _AC;
    u32 _B0;
    u32 _B4;
    u32 _B8;
    u32 _BC;
    u32 _C0;
    u32 _C4;
    u32 _C8;
    u32 _CC;
    u32 _D0;
    u32 _D4;
    u32 _D8;
    u32 _DC;
    u32 _E0;
    u32 _E4;
    u32 _E8;
    u32 _EC;
    u32 _F0;
    u32 _F4;
    u32 _F8;
    u32 _FC;
    u32 _100;
    u32 _104;
    u32 _108;
    u8 _10C;
    u8 _10D;
    u8 _10E;
    u8 _10F;
    f32 _110;
    u32 _114;
    f32 _118;
    u32 _11C;
    u32 _120;
    u32 _124;
    u8 _128;
    u8 _129[32];
    u8 _149;
    u8 _14A;
    u8 _14B;
    s32 _14C;
    HashSortTable *mHashSortTable; // _150
    u32 _154;
};