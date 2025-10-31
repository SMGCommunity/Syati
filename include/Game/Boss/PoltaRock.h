#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/Enemy/WalkerStateBindStarPointer.h"

class Polta;

class PoltaRock : public LiveActor {
public:
	PoltaRock(const char*);

	virtual ~PoltaRock();
	virtual void init(const JMapInfoIter& rIter);
	virtual void kill();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	void start(Polta*, const TVec3f&, const TVec3f&);
	void setColorWhite();
	void setColorBlack();
	void setColorYellow();
	void exeFloat();
	void exeSign();
	void exeMove();
	void generateKill();
	bool isEnableAttack() const;
	bool isEnableExplosion() const;
	bool tryPointBind(); // SMG2 Exclusive

	Polta* mOwner; //0x90
	WalkerStateBindStarPointer* _94; // 0x94
	TQuat4f _98; // 0x98
	TVec3f _A8; // 0xA8
	TVec3f _B4; // 0xB4
	s32 mType; // 0xC0 - 0 = White (Empty), 1 = Black (Bomb Boo), 2 = Gold (Coin)
};

namespace NrvPoltaRock {
	NERVE(PoltaRockNrvFloat);
	NERVE(PoltaRockNrvSign);
	NERVE(PoltaRockNrvMove);
	NERVE(PoltaRockNrvSupportFreeze); // Exclusive to SMG2
}