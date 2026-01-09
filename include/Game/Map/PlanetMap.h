#pragma once

#include "Game/LiveActor/LiveActor.h"

class LodCtrl;
class ModelObj;

class PlanetMap : public LiveActor {
public:
    PlanetMap(const char*);

    const char* mObjectName; // 0x90
    TVec3f _94; // 0x94 : Seems to be related to clipping
    LodCtrl* mLodCtrl; // 0xA0
    ModelObj* mBloomModel; // 0xA4
    ModelObj* mWaterModel; // 0xA8
    ModelObj* mIndirectPlanetModel; // 0xAC
    s32 _B0; // 0xB0 : Effect related, maybe effect count?
};