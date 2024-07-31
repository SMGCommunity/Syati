#pragma once

#include "syati.h"

class TimeAttackClock : public LiveActor {
public:
	TimeAttackClock(const char* pName);

	virtual void init(const JMapInfoIter& rIter);
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	TMtx34f mMtxTR; // _90
	TMtx34f mEffectMtx; // _C0
	s32 _F0; //_F0
	u32 mAddTime; //_F4
};

namespace NrvTimeAttackClock {
	NERVE(NrvCollect);
	NERVE(NrvWait);
};