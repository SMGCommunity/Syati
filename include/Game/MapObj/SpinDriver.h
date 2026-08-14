#pragma once

#include "Game/LiveActor.h"
#include "Game/MapObj/SpinDriverPathDrawer.h"

class SpinDriverCamera;

class SpinDriver : public LiveActor {
public:
    SpinDriver(const char*);

    virtual ~SpinDriver();
    virtual void init(const JMapInfoIter&);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual bool receiveOtherMsg(u32, HitSensor*, HitSensor*);

    void initParamFromJMapInfo(const JMapInfoIter&);
    void initShootPath(const JMapInfoIter&);
    void initEventCamera(const JMapInfoIter&);
    bool tryStartShoot();
    bool tryEndCapture();
    bool tryShoot();
    bool tryEndShoot();
    bool tryForceCancel();
    bool tryEndCoolDown();
    bool trySwitchOff();
    void exeNonActive();
    void exeAppear();
    void exeWait();
    void exeCapture();
    void exeShootStart();
    void exeShoot();
    void exeCoolDown();
    bool startBind(HitSensor*);
    void cancelBind();
    void updateBindPosition();
    void moveBindPosToCenter();
    void updateBindActorMatrix(f32);
    void calcBindActorMatrix();
    void calcParabolicBindPose();
    void turnBindHead(const TVec3f&, f32);
    void calcShootMotionTime();
    void startCamera();
    void updateCamera();
    void cancelCamera();
    void endCamera();
    bool canStartBind() const;
    bool canBind(HitSensor*) const;

    LiveActor *_90;
    SpinDriverShootPath* mShootPath;        // _94
    SpinDriverCamera* mSpinDriverCamera;    // _98
    Mtx _9C;
    TQuat4f _CC;
    TQuat4f _DC;
    TVec3f _EC;
    TVec3f _F8;
    TVec3f _104;
    TVec3f _110;
    TVec3f _11C;
    TVec3f _128;
    f32 _134;
    f32 _138;
    f32 _13C;
    TVec3f _140;
    f32 _14C;
    f32 _150;
    f32 _154;
    s32 _158;
    u32 _15C;
    u32 _160;
    u32 _164;
    f32 _168;
    u8 _16C;
    s32 _170;
    bool _174;
    u8 _175;
    bool _176;
};

namespace SpinDriverUtil {
    void setShadowAndClipping(LiveActor *, TVec3f *, f32, f32, f32 *);
};