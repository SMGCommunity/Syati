#pragma once

#include "revolution.h"
#include "syati.h"

class PowerStar : public LiveActor {
public:
    PowerStar(const char *pName);
    virtual void init(const JMapInfoIter& rIter);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void makeActorAppeared();
    void requestAppear();
    void setDemoAppearPos(const TVec3f&);
    bool isEndAppearPos() const;
    void offAppearDemo();
    void setupColor(const NameObj*, s32);
    void setupColorAtResultSequence(LiveActor*, bool);
    void requestPointLight(const LiveActor*, const NameObj*, s32);
    void requestPointLightAtResultSequence(const LiveActor*);
    f32 getPowerStarWaitRotateSpeed();
    void getBtpFrameCurrentStage(s32);
    void isCurrentStageKoopaVs3();
    void initShadowPowerStar(LiveActor*, bool);
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual bool receiveMsgPlayerAttack(u32, HitSensor*, HitSensor*);
    virtual bool receiveOtherMsg(u32, HitSensor*, HitSensor*);
    void initMapToolInfo(const JMapInfoIter&);
    void initModel();
    void initSensorGrandStar();
    void initShadow(const JMapInfoIter&);
    void initPosture();
    void endAppearDemo();
    LiveActor* getNearestAppearPoint(const TVec3f&);
    LiveActor* getAppearCameraActor();
    ActorCameraInfo* getAppearCameraInfo() const;
    void requestAppearOrWait();
    const char* getStarGetAnimCameraName() const;
    void calcAppearDemoRiseTrans(const TVec3f*, f32);
    void applyAppearDemoRiseTrans(const TVec3f*, f32, f32);
    void processWait(f32);
    void calcStageClearDemoMtx();
    void startExistLevelSound();
    void exeAppearDemoRise();
    void exeAppearDemoMove();
    void exeWait();
    void exeStageClearDemo();

    s32 mPowerStarId; // 0x90
    bool mAppearDemo; // 0x94
    TVec3f mDemoAppearPos; // 0x98
    TVec3f _A4;
    TVec3f _B0;
    TMtx34f _BC;
    TMtx34f mModelObjMtx; // 0xEC
    LiveActor* mCameraActor; // 0x11C
    DemoObj* mDemoObjPeach; // 0x120
    DemoObj* mDemoObjTicoBaby; // 0x124
    DemoObj* mDemoObjSupportTico; // 0x128
    bool mInvalidateClipping; // 0x12C
    bool _12D;
    s32 mColor; // 0x130
    bool isGrandStar; // 0x134
    bool isGreenStar; // 0x135
    bool mCalcAppearanceGravity; // 0x136
    bool mIgnoreGravity; // 0x137
    bool mAppearPointPos; // 0x138
    ActorCameraInfo mActorCameraInfo; // 0x13C
    LiveActor* mNearestAppearPoint; // 0x140
    TMtx34f _144;
    bool isUseStageSwitchAwake; // 0x174
};
