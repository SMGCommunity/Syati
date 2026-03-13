#pragma once

#include "revolution.h"

class J3DAnmBase
{
public:
    J3DAnmBase();

    virtual ~J3DAnmBase();

    u8 _4;
    u8 _5;
    u16 _6;
    f32 _8;
};

class J3DFrameCtrl
{
public:
    enum Attribute_e {
        /*  -1 */ EMode_NULL = -1,
        /* 0x0 */ EMode_NONE,
        /* 0x1 */ EMode_RESET,
        /* 0x2 */ EMode_LOOP,
        /* 0x3 */ EMode_REVERSE,
        /* 0x4 */ EMode_LOOP_REVERSE,
    };

    virtual ~J3DFrameCtrl();

    void init(s16);
    bool checkPass(f32);
    void update();

    /* 0x04 */ u8 mAttribute;
    /* 0x05 */ u8 mState;
    /* 0x06 */ s16 mStart;
    /* 0x08 */ s16 mEnd;
    /* 0x0A */ s16 mLoop;
    /* 0x0C */ f32 mRate;
    /* 0x10 */ f32 mFrame;
};
