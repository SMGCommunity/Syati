#pragma once

#include "Game/NameObj/NameObj.h"
#include "Game/Map/WaterInfo.h"

//class OceanBowl;
//class OceanRing;
class OceanSphere;
//class WhirlPool;
//class WhirlPoolAccelerator;
class WaterStream;
class WaterCameraFilter;

class WaterAreaHolder : public NameObj {
public:
    WaterAreaHolder();

    virtual ~WaterAreaHolder();
    virtual void movement();

    //void entryOceanBowl(OceanBowl*); // Removed in SMG2
    //void entryOceanRing(OceanRing*); // Removed in SMG2
    void entryOceanSphere(OceanSphere*);
    void entryWaterStream(WaterStream*); // New to SMG2

    s32 mOceanSphereNum;
    OceanSphere** mOceanSpheres;
    s32 mWaterStreamNum;
    WaterStream** mWaterStreams;
    bool mIsBloomActive;
    WaterInfo mWaterInfo;
    WaterCameraFilter* mCameraFilter;
    bool mIsAutomaticBloom; // Enabled if in HeavenlyBeachGalaxy OR OceanRingGalaxy... Even though neither exist in SMG2
};

class WaterAreaFunction {
public:
    //static void entryOceanBowl(OceanBowl*); // Removed in SMG2
    //static void entryOceanRing(OceanRing*); // Removed in SMG2
    static void entryOceanSphere(OceanSphere*);
    //static void entryWhirlPool(WhirlPool*); // Removed in SMG2
    //static void entryWhirlPoolAccelerator(WhirlPoolAccelerator*); // Removed in SMG2
    static void entryWaterStream(WaterStream*); // New to SMG2
    static void createWaterAreaHolder();
    static bool tryInOceanArea(const TVec3f&, WaterInfo*);
    //static bool tryInWhirlPoolAccelerator(const TVec3f&, TVec3f*); // Removed in SMG2
    static bool isCameraInWaterForCameraUtil();
    static f32 getCameraWaterDepth();
    static WaterInfo* getCameraWaterInfo();
    static void pauseOffWaterArea();
};
