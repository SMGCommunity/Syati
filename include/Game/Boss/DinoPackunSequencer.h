#pragma once

#include "revolution.h"
#include "Game/System/NerveExecutor.h"

class DinoPackun;

class DinoPackunSequencer : public NerveExecutor {
public:
	DinoPackunSequencer(const char*, DinoPackun*);

	~DinoPackunSequencer();
	virtual void start();
	virtual void init();
	virtual bool isUseEggShell() const;
	virtual s32 getVsCount() const;
	virtual void update();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPush(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual void attackSensorTail(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttackTail(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveOtherMsgTail(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	DinoPackun* mHost; //0x08
	s32 _C; // 0x0C
};