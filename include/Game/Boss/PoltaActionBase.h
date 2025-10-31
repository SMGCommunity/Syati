#pragma once

#include "Game/LiveActor/ActorStateBase.h"

class Polta;
class HitSensor;

class PoltaActionBase : public ActorStateBaseInterface {
public:
	PoltaActionBase(const char*, Polta*);

	virtual ~PoltaActionBase();

    virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
    virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

    bool updateWait(); // Always returns false...
    bool updateDamageBody(bool);
    bool updateBreakBody();
    bool updateDamageCore();

    Polta* mPoltaPtr;
    s32 _10; // Unknown
};