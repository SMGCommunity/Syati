#pragma once

#include "Game/LiveActor/LiveActor.h"

class GCaptureTargetable;

class GCapture : public LiveActor
{
public:
    GCapture(const char *pName);
    virtual ~GCapture();
    virtual void init(const JMapInfoIter &);
    virtual void draw() const;
    virtual void control();
    virtual void attackSensor(HitSensor *, HitSensor *);
    virtual bool receiveMsgEnemyAttack(u32, HitSensor *, HitSensor *);
    virtual bool receiveOtherMsg(u32, HitSensor *, HitSensor *);
    
    bool requestBind(HitSensor *);
    bool requestCancelBind();
    bool requestDamageCancel(u32);
    
    bool tryCapture();
    bool tryCancelCapture();
    bool tryEndTraction();
    bool tryRecapture();
    bool tryRetraction();
    bool tryBreak();
    bool tryFireDamage();
    bool tryRelease();

    void exeCoolDown();
    void exeWait();
    void exeCapture();
    void exeRecapture();
    void exeTraction();
    void exeHold();
    void exeBreak();
    
    void endBindByDamage(s32);
    void endBindByFireDamage();
    
    void calcBindActorPose();
    void updateBindActorMatrix();
    
    bool canRequestTarget() const;
    bool canCancelBind() const;

    void upTractPower();
    void downTractPower();
    void fillGapBindTrans();
    void updateRibbon(TVec3f *, s32);
    void updateRibbonPointEffectMatrix(TVec3f *);
    void addRotateAccelPointing();
    void tryAddVelocityReflectJumpCollision();

    bool requestTarget(GCaptureTargetable *);
    bool isRequestedTarget(GCaptureTargetable *);
    void decideTractTarget();
    void releaseTractTarget();
    void endStarPointerMode();
    void updateCameraTargetMatrix();
};

namespace MR {
    GCapture *createGCapture();
    bool isRequestedGCaptureTarget(GCaptureTargetable *);
    void noticeInTouchableRange();
    bool isPlayerGCaptured();
}