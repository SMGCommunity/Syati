#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/MapObj/ClipArea.h"

class ClipAreaDrop : ClipArea {
    public:
        ClipAreaDrop(const char *, const char *);

        f32 setBaseSize(f32);

        const char *_C4;
        u32 _C8;
        f32 _CC;
        s32 _D0;
        s32 _D4;
        s32 _D8;
        u32 _DC;
        bool _E0;
};
