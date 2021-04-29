#pragma once

#include "JGeometry/TVec3.h"
#include "kamek.h"

class HitSensor;

class HitSensorInfo
{
public:
    HitSensorInfo(const char *, HitSensor *, const TVec3f *, Mtx *, const TVec3f &, bool);

    void update();
    void doObjCol();

    const char* mName; // _0
    s32 mHashCode; // _4
    HitSensor* mSensor; // _8
    TVec3f _C;
    TVec3f* _18;
    Mtx* _1C;
    bool _20;
};