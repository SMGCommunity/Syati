#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/MapObj/ClipArea.h"

class ClipAreaDrop : public ClipArea {
    public:
        ClipAreaDrop(const char *, const char *);

        void setBaseSize(f32);
        void setOpeningAndClosure(s32, s32);

        const char *_C4;
        ClipAreaShapeSphere* mSphere; //_C8
        f32 mRadius; //_CC
        s32 _D0;
        s32 _D4;
        s32 _D8;
        s32 mTime; //_DC
        bool _E0;
};
