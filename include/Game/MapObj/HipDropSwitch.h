#pragma once

#include "Game/LiveActor/LiveActor.h"

class SpringValue;
class MapObjConnector;
class CollisionParts;

class HipDropSwitch : public LiveActor {
public:
    HipDropSwitch(const char*);

    virtual ~HipDropSwitch();
    virtual void init(const JMapInfoIter& rIter);
    virtual void initAfterPlacement();
    virtual void calcAnim();
    virtual void makeActorAppeared();
    virtual void makeActorDead();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

    bool trySwitchDown();
    bool tryOn();
    bool isPlayerOnTop();

    void exeOff();
    void exeSwitchDown();
    void exeOn();


    u32 _90;
    SpringValue* mSpringValue;    // 0x94
    MapObjConnector* mConnector;  // 0x98
    CollisionParts* _9C;
    TPos3f _A0;
    u8 _D0;
    u8 _D1;
    u8 _D2;
};

namespace NrvHipDropSwitch {
    NERVE(HipDropSwitchNrvOff);
    NERVE(HipDropSwitchNrvSwitchDown);
    NERVE(HipDropSwitchNrvOn);
}