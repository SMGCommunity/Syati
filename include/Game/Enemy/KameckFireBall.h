#pragma once

#include "Game/Enemy/KameckBeam.h"

class KameckFireBall : public LiveActor, public AbstractKameckBeamActor {
public:
	KameckFireBall(const char*);

	virtual ~KameckFireBall();
	virtual void init(const JMapInfoIter&);
	virtual void makeActorAppeared();
	virtual void kill();
	virtual void makeActorDead();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
};