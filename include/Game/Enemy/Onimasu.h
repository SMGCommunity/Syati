#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ActorStateParamScale.h"

class OnimasuFunction {
public:
    static void getPolygonOnRailPoint(TVec3f*, TVec3f*, const LiveActor*, int);
};

class Onimasu : public LiveActor {
public:

    virtual ~Onimasu();

    Onimasu(const char*);

    virtual void initFromRailPoint() = 0;
    virtual void incrementNextPoint() = 0;
    virtual void collectRailPointInfo() = 0;
    virtual int getNextPointNo() const = 0;
    virtual int getLastPointNo() const = 0;
    virtual TVec3f* getLastPointNormal() const = 0;
    virtual TVec3f* getNextPointNormal() const = 0;
    virtual void startMoveInner();
    virtual void updatePoseInner();

    void init(const JMapInfoIter&);
    void initAfterPlacement();
    void movement(); // New to SMG2
    void control(); // New to SMG2
    void calcAndSetBaseMtx();


    void calcTargetPose();
    void updatePose();
    void land();
    bool calcTurnDirection(f32*) const;
    void updateStompVelocity();
    void calcGravityDir(TVec3f*) const;
    f32 getGravityScalar() const;
    int getTimeToNextPoint() const;
    void emitEffectLand();

    void exeWaitForSwitchOn();
    void exeWait();
    void exeMove();
    void exeStamp();


    ActorStateParamScale* mParamScale; // 0x90 (New to SMG2)
    s32 mPauseDelay; // 0x94 (New to SMG2)
    s32 mMoveTime; // 0x98 (New to SMG2)
    s32 mCometPauseDelay; // 0x9C (New to SMG2)
    s32 mCometMoveTime; // 0xA0 (New to SMG2)
    TMtx34f _A4;
    TVec3f _D4;
    TVec4f _E0;
    TVec4f _F0;
    TVec4f _100;
    TVec3f _110;
};

namespace NrvOnimasu {
    NERVE(HostTypeWaitForSwitchOn);
    NERVE(HostTypeWait);
    NERVE(HostTypeWaitForStamp);
    NERVE(HostTypeJump);
    NERVE(HostTypeStamp);
}