#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/Util/SpringValue.h"

class GCaptureTargetable;
class GCaptureRibbon;
class CameraTargetMtx;

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

    TPos3f _90;
    TQuat4f _C0;
    TVec3f _D0;
    TVec3f _DC;
    TVec3f _E8;
    TVec3f _F4;
    TVec3f _100;
    LiveActor* _10C;
    s32 _110;
    s32 _114;
    GCaptureRibbon* mRibbon; // _118
    CameraTargetMtx* mCameraTargetMtx; //_11C
    SpringValue* mSpringValue; // _120
    f32 _124;
    f32 _128;
    f32 _12C;
    s32 _130;
    f32 _134;
    s32 mGuidanceTimer; //_138
    bool mIsPointed; //_13C
    bool _13D; //_13D
};

namespace MR {
    GCapture *createGCapture();
    bool isRequestedGCaptureTarget(GCaptureTargetable *);
    void noticeInTouchableRange();
    bool isPlayerGCaptured();
}

namespace NrvGCapture {
    NERVE(GCaptureNrvWait);
    ENDABLE_NERVE(GCaptureNrvCapture);
    ENDABLE_NERVE(GCaptureNrvRecapture);
    NERVE(GCaptureNrvTraction);
    NERVE(GCaptureNrvHold);
    NERVE(GCaptureNrvBreak);
    NERVE(GCaptureNrvCoolDown);
}