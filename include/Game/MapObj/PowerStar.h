#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ModelObj.h"
#include "Game/LiveActor/ActorCameraInfo.h"
#include "Game/MapObj/PowerStarAppearPoint.h"

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
    PowerStarAppearPoint* getNearestAppearPoint(const TVec3f&);
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
    virtual ~PowerStar();

    s32 mPowerStarId; //_90
    bool mUseAppearDemo; //_94
    TVec3f _98; //_98
    TVec3f _A4; //_A4
    TVec3f _B0; //_B0
    TMtx34f _BC; //_BC
    TMtx34f _EC; //_EC
    ModelObj* mDemoStar; //_11C
    DemoObj* mDemoPeach; //_120 PeachAnim
    DemoObj* mDemoTicoBaby; //_124 TicoBabyAnim
    DemoObj* mDemoSupportTico; //_128 SupportTico
    bool mIsAppearDemo; //_12C
    bool _12D; //_12D
    s32 mColor; //_130
    bool mIsGrand; //_134
    bool mIsGreen; //_135
    bool mAppearanceGravity; //_136 ObjArg1
    bool mIgnoreGravity; //_137 ObjArg2
    bool mAppearNearest; //_138 ObjArg4
    ActorCameraInfo* mActorCameraInfo; //_13C
    PowerStarAppearPoint* mNearestAppearPoint; //_140
    TMtx34f _144; //_144
    bool mHasSwitchAwake; //_174
};
