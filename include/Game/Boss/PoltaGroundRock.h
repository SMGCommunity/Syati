#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ModelObj.h"
#include "Game/Enemy/WalkerStateBindStarPointer.h"

class Polta;

class PoltaGroundRock : public LiveActor {
public:
	PoltaGroundRock(const char*);

	virtual ~PoltaGroundRock();
	virtual void init(const JMapInfoIter& rIter);
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	void initBreakModel();
	void start(LiveActor*, const TVec3f&); // The LiveActor* ends up only being used as Polta* in-game
	void requestBreak();
	bool isEnableAttack() const;
	bool isEnableBreak() const;

	void exeSign();
	void exeJut();
	void exeWait();
	void exeBreak();

	LiveActor* mOwner;		// 0x90
	ModelObj* mBreakModel;	// 0x94
	TQuat4f _98;			// 0x98
	TVec3f _A8;				// 0xA8 - Effect SRT related
};

namespace NrvPoltaGroundRock {
	NERVE(PoltaGroundRockNrvSign);
	NERVE(PoltaGroundRockNrvJut);
	NERVE(PoltaGroundRockNrvWait);
	NERVE(PoltaGroundRockNrvBreak);
}