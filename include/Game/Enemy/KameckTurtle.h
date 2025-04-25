#pragma once

#include "Game/Enemy/KameckBeam.h"
#include "Game/MapObj/JetTurtle.h"

class KameckTurtle : public LiveActor, public AbstractKameckBeamActor {
public:
	KameckTurtle(const char*);

	virtual ~KameckTurtle();
	virtual void init(const JMapInfoIter&);
	virtual void makeActorAppeared();
	virtual void makeActorDead();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	void appearJetTurtle(bool);

	JetTurtle* mJetTurtle; // 0x98
	TQuat4f _9C; // 0x9C
	TVec3f _AC; // 0xAC
	TVec3f _B8; // 0xB8
};

namespace NrvKameckTurtle {
	NERVE(KameckTurtleNrvRun);
	NERVE(KameckTurtleNrvWait);
}