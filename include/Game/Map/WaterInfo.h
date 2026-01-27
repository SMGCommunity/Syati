#pragma once

#include "revolution.h"
#include "JSystem.h"

class OceanBowl;
class OceanRing;
class OceanSphere;
class WaterArea;
class WaterStream;

class WaterInfo {
public:
    WaterInfo();

    bool isInWater() const;
    void clear();

    f32 mCameraWaterDepth;
    f32 _4;
    TVec3f mSurfacePos;
    TVec3f mSurfaceNormal;
    f32 mWaveHeight;
    TVec3f mStreamVec;
    f32 mEdgeDistance;
    TVec3f mEdgePos;
    WaterArea* mWaterArea;
    OceanBowl* mOceanBowl;
    OceanRing* mOceanRing;
    OceanSphere* mOceanSphere;
    WaterStream* mWaterStream;
};
