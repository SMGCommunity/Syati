#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class ArrowSwitch : public LiveActor {
public:
	ArrowSwitch(const char*);

	virtual ~ArrowSwitch();
	virtual void init(const JMapInfoIter& rIter);
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPush(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	bool requestPunch(HitSensor*, HitSensor*);
	void listenOnSwitch();
	void listenOffSwitch();

	void exeWait();
	void exeRotate();
	void exeLock();

	bool isPlusLimit() const;
	bool isMinusLimit() const;
	s32 getOneStep() const;

	f32 _90;                // 0x90
	s32 _94;                // 0x94
	f32 _98;                // 0x98
	s32 mRotationDirection; // 0x9C [ObjArg0]
	s32 mActivationMode;    // 0xA0 [ObjArg1]
	bool _A4;               // 0xA4
	u8 _A5;                 // 0xA5 (Unused?)
	bool _A6;               // 0xA6
};

namespace NrvArrowSwitch {
	NERVE(ArrowSwitchNrvWait);
	NERVE(ArrowSwitchNrvRotate);
	NERVE(ArrowSwitchNrvLock);
	NERVE(ArrowSwitchNrvStop);
}