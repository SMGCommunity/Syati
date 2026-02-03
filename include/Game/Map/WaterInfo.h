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

    f32 mCameraWaterDepth;     // 0x00
    f32 _4;                    // 0x04
    TVec3f mSurfacePos;        // 0x08
    TVec3f mSurfaceNormal;     // 0x14
    f32 mWaveHeight;           // 0x20
    TVec3f mStreamVec;         // 0x24
    f32 mEdgeDistance;         // 0x30
    TVec3f mEdgePos;           // 0x34
    WaterArea* mWaterArea;     // 0x40
    OceanBowl* mOceanBowl;     // 0x44
    OceanRing* mOceanRing;     // 0x48
    OceanSphere* mOceanSphere; // 0x4C
    WaterStream* mWaterStream; // 0x50
};
