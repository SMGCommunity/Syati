#pragma once

#include "Game/Boss/PoltaActionBase.h"


class PoltaStateStagger;
class PoltaStateGroundRockAttack;
class PoltaStateGenerateRock;

class PoltaStateAttackGround;
class PoltaStatePunch;

class PoltaBattleLv2 : public PoltaActionBase {
public:
	PoltaBattleLv2(Polta*);

	virtual ~PoltaBattleLv2();
	virtual void appear();
	virtual void control();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	bool tryAttackGround();
	void setNerveGenerateRock();
	bool tryGenerateRock();

	void exeBreakBody();
	void exeStagger();
	void exeDamageCore();

	bool isEnableSensor(HitSensor*) const;
	bool isEnableAttack(HitSensor*) const;
	bool isEnableDamage() const;
	bool isEnableScream() const;
	void addDamageBody();


	PoltaStateAttackGround* mStateAttackGround; // 0x14
	PoltaStatePunch* mStatePunch; // 0x18
	PoltaStateStagger* mStateStagger; // 0x1C
	PoltaStateGenerateRock* mStateGenerateRock; // 0x20
	PoltaStateGroundRockAttack* mStateGroundRockAttack; // 0x24
	s32 _28;
	s32 _2C;
};

namespace NrvPoltaBattleLv2 {
	NERVE(PoltaBattleLv2NrvWait);
	NERVE(PoltaBattleLv2NrvPunch);
	NERVE(PoltaBattleLv2NrvAttackGround);
	NERVE(PoltaBattleLv2NrvGenerateGroundRock);
	NERVE(PoltaBattleLv2NrvGenerateRock);
	NERVE(PoltaBattleLv2NrvDamageBody);
	NERVE(PoltaBattleLv2NrvBreakBody);
	ENDABLE_NERVE(PoltaBattleLv2NrvStagger);
	NERVE(PoltaBattleLv2NrvDamageCore);
}