#pragma once

#include "Game/LiveActor.h"
#include "revolution.h"

class EarthenPipe : public LiveActor {
public:
    EarthenPipe(const char *pName);
    ~EarthenPipe();
    virtual void init(const JMapInfoIter &rIter);
    virtual void makeActorAppeared();
    virtual void control();
    virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);
    virtual MtxPtr getBaseMtx() const;
    
    bool tryShowUp();
    bool tryHideDown();
    bool isNerveShowUp() const;
    void exeWait();
    void exeReady();
    void exePlayerIn();
    void exeTargetPipeShowUp();
    void exePlayerOut();
    void exeLaunch();
    void exeInvalid();
    void exeShowUp();
    void exeHideDown();
    void calcTrans(f32);
    void launchPlayer();
    bool isValidBehavior();

    TVec3f _90;
    TVec3f _9C;
    f32 _A8;
    bool mIgnoreGravity;            // _AC
    s32 mBehavior;                  // _B0
    LiveActor *_B4;
    MtxPtr _B8;
    MtxPtr _BC;
    TPos3f _C0;
    u32 _F0;
    Mtx _F4;
    Mtx _124;
    Mtx _154;
    f32 _184;
    f32 mHorizontalExitForce;
    f32 mVerticalExitForce;
    s32 mBgmIndexLeft;
    s32 mBgmStateExited;
    u32 _198;
    s32 _19C;
    u32 _1A0;
    PartsModel *mStreamModel;       // _1A4
    bool mIsInWater;
    ActorCameraInfo *mCameraInfo;   // _1AC
};

namespace MR {
    void setBGMParams(s32 *pBgmIndexLeft, s32 *pBgmStateExited, const JMapInfoIter &rIter);
    bool startActionIfExist(const LiveActor *pActor, const char *pAnimName);
    bool isExistAction(const LiveActor *pActor, const char *pAnimName);
}

namespace NrvEarthenPipe {
    NERVE(EarthenPipeNrvWait);
    NERVE(EarthenPipeNrvReady);
    NERVE(EarthenPipeNrvPlayerIn);
    NERVE(EarthenPipeNrvTargetPipeShowUp);
    NERVE(EarthenPipeNrvPlayerOut);
    NERVE(EarthenPipeNrvLaunch);
    NERVE(EarthenPipeNrvInvalid);
    NERVE(EarthenPipeNrvHide);
    NERVE(EarthenPipeNrvShow);
    NERVE(EarthenPipeNrvWaitToShowUp);
    NERVE(EarthenPipeNrvShowUp);
    NERVE(EarthenPipeNrvWaitToHideDown);
    NERVE(EarthenPipeNrvHideDown);
}