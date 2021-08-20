#pragma once

#include "JSystem.h"

class HitSensor;

class HitSensorInfo
{
public:
    HitSensorInfo(const char *, HitSensor *, const TVec3f *, Mtx *, const TVec3f &, bool);

    void setFollowPos(const TVec3f *);
    void setFollowMtx(MtxPtr);
    void update();
    void doObjCol();

    const char* mName; // _0
    s32 mHashCode; // _4
    HitSensor* mSensor; // _8
    TVec3f _C;
    TVec3f* mFollowPos;
    Mtx* mFollowMtx;
    bool _20;
};