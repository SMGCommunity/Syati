#pragma once

#include "syati.h"

class PauseBlur : public NameObj {
public:
    PauseBlur(const char*);
    virtual ~PauseBlur();
    virtual void init(const JMapInfoIter&);
    virtual void movement();
    virtual void draw();
    virtual void calcAnim();

    s32 _14;
    s32 _18;
    bool _1C;
    s32 _20;
    s32 _24;
    s32 _28;
    s32 _2C;
    s32 _30;
    s32 _34;
};