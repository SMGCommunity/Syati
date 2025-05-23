#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/MapObj/MapObjConnector.h"
#include "Game/Player/YoshiLockOnTarget.h"
#include "Game/Util/JMapIdInfo.h"

class RestartObj : public LiveActor {
public:
    RestartObj(const char *pName);

    virtual ~RestartObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual void initAfterPlacement();
    virtual void calcAndSetBaseMtx();
    virtual void updateHitSensor(HitSensor *pSensor);
    virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

    void exeWait();
    void exeCollect();
    void exeShake();
    void exeAfter();
    void changeTexture(bool);

    JMapIdInfo* mRestartId;          // 0x90
    MapObjConnector* mConnector;     // 0x94
    YoshiLockOnTarget* mYoshiTarget; // 0x98
};

namespace NrvRestartObj {
    NERVE(RestartObjNrvWait);
    NERVE(RestartObjNrvCollect);
    NERVE(RestartObjNrvCollectAfter);
    NERVE(RestartObjNrvShake);
    NERVE(RestartObjNrvAfter);
};