#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/LiveActor/LiveActor.h"

class Tamakoro;
class TalkMessageCtrl;

class TamakoroTutorial : public LiveActor {
public:
	TamakoroTutorial(const char*);

	virtual ~TamakoroTutorial();
	virtual void init(const JMapInfoIter& rIter);
	virtual void initAfterPlacement();
	virtual void control();
	virtual void updateHitSensor(HitSensor* pSensor);
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	bool isNeedTutorial();
	void requestStart();
	void requestEnd();
	void startTimerSound(s32, s32);

	void exeFirst();
	void exeDenyTalk();
	void exeFirstForceTalk();
	void exeWaitRideTalk();
	void exeWaitRide();
	void exeWaitRaiseTalk();
	void exeWaitRaiseStable();
	void exeRaiseOk();
	void exeRaiseOkTalk();
	void exeFinalTalk();
	void exeWait();
	void exeTrample();
	void exeRecover();

	Tamakoro* mOwner; // 0x90
	TalkMessageCtrl* mTutorial1Msg; // 0x94
	TalkMessageCtrl* mTutorial2Msg; // 0x98
	TVec3f mCorePadAccel; // 0x9C
	bool _A8;
	bool _A9;
};

TVec3f hRaiseAcc;

namespace NrvTamakoroTutorial {
	NERVE(HostTypeNrvFirst);
	NERVE(HostTypeNrvFirstForceTalk);
	NERVE(HostTypeNrvWaitRideTalk);
	NERVE(HostTypeNrvWaitRide);
	NERVE(HostTypeNrvWaitRaiseTalk);
	NERVE(HostTypeNrvWaitRaiseStable);
	NERVE(HostTypeNrvRaiseOk);
	NERVE(HostTypeNrvRaiseOkTalk);
	NERVE(HostTypeNrvFinalTalk);
	NERVE(HostTypeNrvWait);
	NERVE(HostTypeNrvDirectRide);
	NERVE(HostTypeNrvTrampleFront);
	NERVE(HostTypeNrvTrampleBack);
	NERVE(HostTypeNrvRecoverFront);
	NERVE(HostTypeNrvRecoverBack);
}