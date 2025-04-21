#pragma once

#include "revolution/types.h"

typedef s16* (*MixCallback)(s32);

enum JASMixMode {

};

namespace JASDriver {
    f32 getDacRate();
    u32 getSubFrames();

    static MixCallback extMixCallback;
    static JASMixMode sMixMode;
};