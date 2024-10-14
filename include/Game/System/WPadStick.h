#pragma once

#include "Game/System/WPad.h"

class WPadStick {
public:
    WPadStick(const WPad *);
    void update();
    bool isChanged() const;

    const WPad *mWPad;
    f32 mStickX; // _4
    f32 mStickY; // _8
    f32 _C;
    u32 _10;
    u32 _14;
    u32 _18;
    u8 _1C;
    u8 _1D;
    u32 _20;
    u32 _24;
    u8 _28;
    u8 _29;
};