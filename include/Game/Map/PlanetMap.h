#pragma once

#include "Game/LiveActor/LiveActor.h"

class LodCtrl;
class ModelObj;

class PlanetMap : public LiveActor {
public:
    PlanetMap(const char*);

    virtual ~PlanetMap();
    virtual void init(const JMapInfoIter& rIter);
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void startClipped();
    virtual void endClipped();
    virtual void control();

    virtual void connectToScene();
    virtual f32 getFarClipDistance() const;
    virtual f32 getLowMovementType() const;
    virtual void initDemoActionAppear(const JMapInfoIter& rIter);
    virtual bool useProjmapMtx() const;
    virtual void initProjmapMtx();
    virtual void initSwitchBListener(const JMapInfoIter& rIter);
    virtual void hide();
    virtual void show();
    virtual void initMyEffect();
    virtual bool tryEmitMyEffect();
    virtual bool tryDeleteMyEffect();

    void initClipping(const JMapInfoIter& rIter);
    void initModel(const char*, const JMapInfoIter& rIter);
    void initBloomModel(const char*);
    void initEffects(s32* outNumEffects, const char* effectGroupName, s32 maxEffectNum); // Calls MR::registerDemoSimpleCastAll if at least 1 effect exists
    bool tryEmitEffects(const char* effectGroupName, s32 effectNum);
    bool tryDeleteEffects(const char* effectGroupName, s32 effectNum);
    bool tryForceDeleteEffects(const char* effectGroupName, s32 effectNum);

    const char* mObjectName; // 0x90
    TVec3f _94; // 0x94 : Seems to be related to clipping
    LodCtrl* mLodCtrl; // 0xA0
    ModelObj* mBloomModel; // 0xA4
    ModelObj* mWaterModel; // 0xA8
    ModelObj* mIndirectPlanetModel; // 0xAC
    s32 mEffectNum; // 0xB0
};