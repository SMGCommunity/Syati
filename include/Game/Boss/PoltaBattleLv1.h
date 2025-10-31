#pragma once

#include "Game/Boss/PoltaActionBase.h"


class PoltaStateStagger;
class PoltaStateGroundRockAttack;
class PoltaStateGenerateRock;

class PoltaBattleLv1 : public PoltaActionBase {
public:
	PoltaBattleLv1(Polta*);

	virtual void appear();
	virtual void control();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);


	PoltaStateStagger* mStateStagger; // 0x14
	PoltaStateGenerateRock* mStateGenerateRock; // 0x18
	PoltaStateGroundRockAttack* mStateGroundRockAttack; // 0x1C
	s32 _20; // 0x20
	s32 _24; // 0x24
};

namespace NrvPoltaBattleLv1 {
	NERVE(PoltaBattleLv1NrvWait);
	NERVE(PoltaBattleLv1NrvGenerateGroundRock);
	NERVE(PoltaBattleLv1NrvGenerateRock);
	NERVE(PoltaBattleLv1NrvDamageBody);
	NERVE(PoltaBattleLv1NrvBreakBody);
	ENDABLE_NERVE(PoltaBattleLv1NrvStagger);
	NERVE(PoltaBattleLv1NrvDamageCore);
}