#pragma once

#include "JSystem.h"

class CollisionParts;
class HitSensor;

class Triangle
{
public:
    Triangle();

    CollisionParts* mColParts; // _0
    s32 mIndex; // _4
    HitSensor* mSensor; // _8
    TVec3f mFaceNormal; // _C
    TVec3f mEdgeNormal_1;
    TVec3f mEdgeNormal_2;
    TVec3f mEdgeNormal_3;
    TVec3f _3C;
    TVec3f _48;
    TVec3f _54;

};

class HitInfo : public Triangle
{
public:
    HitInfo();

    f32 _60;
    TVec3f _64;
    TVec3f _70;
    TVec3f _7C;
    u8 _88;
};

class TriangleFilterBase
{
public:
    virtual bool isInvalidTriangle(const Triangle *) const = 0;
};
