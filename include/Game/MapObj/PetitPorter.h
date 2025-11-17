#pragma once

// == WIP ==
// All addresses shown are USA

#include "Game/LiveActor/LiveActor.h"

class ActorCameraInfo;
class CameraTargetMtx;
class JointController;
struct JointControllerInfo;

class PetitPorter : public LiveActor {
public:
    PetitPorter(const char*);

    virtual ~PetitPorter();
    virtual void init(const JMapInfoIter& rIter);
    virtual void makeActorAppeared();
    virtual void calcAndSetBaseMtx();
    virtual void updateHitSensor(HitSensor* pSensor);
    virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

    bool calcJoint(TPos3f* pJointMtx, const JointControllerInfo& rJointControllerInfo);

    // Nerve EXE functions

    // Likely const function at 802D9510


    TMtx34f mBaseMatrix; // 0x90
    u32 _C0; // 0xC0
    u32 _C4; // 0xC4
    s32 mTimeLimit; // 0xC8
    f32 _CC; // 0xCC
    f32 _D0; // 0xD0
    LiveActor* _D4; // 0xD4 (probably a host actor?)
    TMtx34f _D8; // 0xD8
    TMtx34f _108; // 0x108
    ActorCameraInfo* mCameraInfo; // 0x138
    CameraTargetMtx* mCameraTargetMtx; // 0x13C
    JointController* mJointController; // 0x140
    u32 _144; // 0x144 (Music Related)
    u32 _148; // 0x148 (Music Related)
};

class PetitPorterWarpPoint : public LiveActor {
public:
    PetitPorterWarpPoint(const char*);

    virtual ~PetitPorterWarpPoint();
    virtual void init(const JMapInfoIter& rIter);

    TMtx34f mBaseMatrix; // 0x90
};

class PetitPorterExitPoint : public LiveActor {
public:
    PetitPorterExitPoint(const char*);

    virtual ~PetitPorterExitPoint();
    virtual void init(const JMapInfoIter& rIter);

    TMtx34f mBaseMatrix; // 0x90
};

class PetitPorterMediator : public NameObj {
public:
    PetitPorterMediator();

    struct Entry {
        PetitPorter* mPetitPorter;        // 0x00
        PetitPorterWarpPoint* mWarpPoint; // 0x04
        PetitPorterExitPoint* mExitPoint; // 0x08
        s32 mId;                          // 0x0C
    };

    virtual ~PetitPorterMediator();
    virtual void initAfterPlacement();

    // If the PetitPorter, PetitPorterExitPoint, or PetitPorterWarpPoint is NULL, then it will not update the Entry's data for that object.
    void entry(PetitPorter*, PetitPorterExitPoint*, PetitPorterWarpPoint*, const JMapInfoIter& rIter);

    s32 mNumEntries; // 0x14
    Entry* mEntries; // 0x18 - Vanilla allocates 32 instances
};

// need to figure out what these do so they can be properly named
namespace NrvPetitPorter {
    // 807D4078 - Wait for SW_A (if applicable)
    // 807D407C -
    // 807D4080 -  [initNerve]
    // 807D4084 -
    // 807D4088 -
    // 807D408C -
    // 807D4090 -
    // 807D4094 -
    // 807D4098 -
    // 807D409C - Return the player after the minigame
    // 807D40A0 -  [NullSub]
}