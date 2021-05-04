#pragma once

#include "Actor/LiveActor/LiveActor.h"

class BlackHole : public LiveActor
{
public:
    BlackHole(const char *);

    virtual ~BlackHole();
    virtual void init(const JMapInfoIter &);
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void makeActorDead();
    virtual void calcAndSetBaseMtx();
    virtual void attackSensor(HitSensor *, HitSensor *);

    bool tryStartDemoCamera();
    void initMapToolInfo(const JMapInfoIter &);
    void initModel();
    void initCubeBox();
    bool isInCubeBox(const TVec3f &);
    void updateModelScale(f32, f32);
    void exeWait();
    void exeDisappear();

    s32 _90;
    f32 _94;
    f32 _98;
    TVec3f _9C;
    s32 _A8;
    Mtx _AC;
    Mtx _DC;
    s32 _10C;
};
