#pragma once

#include "Game/Effect/SimpleEffectObj.h"

/* FINISHED */

class RandomEffectObj : public SimpleEffectObj {
public:
    RandomEffectObj(const char *pName);

    virtual ~RandomEffectObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual void appear();
    virtual void control();

    s32 getRandomTime() const;

    /* 0xA0 */ s32 mStep;
    /* 0xA4 */ s32 mSeStep;
    /* 0xA8 */ s32 mLifeTime;
    /* 0xAC */ s32 mRandWidth;
};
