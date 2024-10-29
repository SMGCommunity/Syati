#pragma once

#include "Game/NameObj.h"
#include "Yoshi.h"
#include "YoshiTargetMark.h"

class YoshiLockOnManager : public NameObj {
public:
    YoshiLockOnManager(Yoshi *);
    virtual ~YoshiLockOnManager();
    virtual void init(const JMapInfoIter &);
    virtual void movement();
    virtual void draw();

    u32 _14;
    u32 _18;
    u8 _1C;
    u8 _1D;
    u8 _1E;
    MR::BothDirPtrList _20;
    MR::BothDirPtrList _2C;
    MR::BothDirPtrList _38;
    YoshiTargetMark **mYoshiTargetMarks; // _44
    u32 _48;
    u8 _4C;
};