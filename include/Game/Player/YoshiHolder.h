#pragma once

#include "Yoshi.h"
#include "YoshiLockOnManager.h"
#include "YoshiArrow.h"
#include "YoshiDashStep.h"
#include "YoshiFruitCounter.h"

class YoshiTongueAction;

class YoshiHolder {
public:
    YoshiHolder(Mario *);

    Yoshi *_0;
    u32 _4;
    YoshiTongueAction *_8;
    YoshiLockOnManager *_C;
    u32 *_10; // 8041BF10
    YoshiArrow *_14;
    PartsModel *mYoshiBalloon; // _18
    YoshiDashStep *_1C;
    YoshiFruitCounter *_20;
    u32 *_24[64];
    u32 _28;
    u32 _2C;
    LiveActor *_30;
    u8 _34;
    u8 _35;
    u32 _38;
    u8 _3C;
    u32 _40;
    u32 _44;
    u8 _48;
    u32 _4C;
};