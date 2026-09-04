#pragma once

#include "Game/LiveActor/LiveActor.h"

class AnimationRandomPlayer;
class JointRumbler;
class YoshiLockOnTarget;
class BenefitItemOneUp;

class Kanina : public LiveActor {
public:
	enum KaninaType {
		KaninaType_Blue = 0,
		KaninaType_Red = 1
	};

	Kanina(const char *pName);
	virtual ~Kanina();
	virtual void init(const JMapInfoIter &rIter);
	virtual void initAfterPlacement();
	virtual void kill();
	virtual void makeActorDead();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveMsgPush(HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor *pSender, HitSensor *pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor *pSender, HitSensor *pReceiver);

	void initForType(const JMapInfoIter &rIter, KaninaType);
	
	bool isPlayerBackward(f32) const;
	bool isStatePossibleToAttack() const;
	bool isStateBlink() const;

	void appearItemTrample();
	void doDamageFireBall(HitSensor *, HitSensor *);
	void startRun();
	void startRunAwayLevelSound();
	
	bool receiveTrample(HitSensor *, HitSensor *);
	bool receiveFireBall(HitSensor *, HitSensor *);
	bool receiveHipDrop(HitSensor *, HitSensor *);
	bool receiveInvincibleAttack(HitSensor *, HitSensor *);

	void exeAppear();
	void exeWait();
	void exeWalk();
	void exeRunAway();
	void exeRunAwayReboundDirection();
	void exeRunAwayBreak();
	void exeAttack();
	void exeVauntAttackSuccess();
	void exeHitWall();
	void exeReboundEach();
	void exeGuard();
	void exeGuardEnd();
	void exeDamageFireBall();
	void exeDig();
	void exeWaitUnderGround();
	void exeFindPlayer();
	void exeTurn();
	void exeTurnEnd();
	void exePointing();

	bool tryAttack(HitSensor *, HitSensor *);
	bool tryPushEach(HitSensor *, HitSensor *);
	bool tryFindPlayer();
	bool tryHitWall();
	bool tryTurn();
	bool tryPointing();

	KaninaType mKaninaType; // _90
	ActorStateBaseInterface* _94; // ctor 0x801ACD60
	JointRumbler* mJointRumbler; // _98
	BenefitItemOneUp* mOneUp; // _9C
	AnimationRandomPlayer* mAnimRandomPlayer; // _A0
	YoshiLockOnTarget* mYoshiLockOnTarget; // _A4
	TVec3f mOriginalPosition; // _A8
	TQuat4f _B4;
	f32 _C0;
	s32 mRunAwayBreakTime; // _C4
	s32 mRunAwayTime; // _C8
	f32 _CC;
	TVec3f _D0;
	TVec3f _DC;
	s32 mWalkTimer; // _E8
	s32 _EC; // Some kind of timer
	s32 _F0;
	bool mNoDig; // _F4
};

namespace NrvKanina {
	NERVE(HostTypeAppear);
	NERVE(HostTypeWait);
	NERVE(HostTypeAttack);
	NERVE(HostTypeVauntAttackSuccess);
	NERVE(HostTypeGuard);
	NERVE(HostTypeGuardEnd);
	NERVE(HostTypeDamageFireBall);
	NERVE(HostTypeDig);
	NERVE(HostTypeWaitUnderGround);
	NERVE(HostTypeFindPlayer);
	NERVE(HostTypeRunAwayBreak);
	NERVE(HostTypeReboundEach);
	NERVE(HostTypeTurn);
	NERVE(HostTypeTurnEnd);
	NERVE(HostTypePointing);
	NERVE(HostTypePointingEnd);
	NERVE(HostTypeWalk);
	NERVE(HostTypeRunAway);
	NERVE(HostTypeRunAwayReboundDirection);
	NERVE(HostTypeHitWall);
};