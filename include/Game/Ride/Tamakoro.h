#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/LiveActor/LiveActor.h"

class AudTamakoroBgmCtrl;
class SphereAccelSensorController;
class TamakoroTutorial;

class Tamakoro : public LiveActor {
public:
	Tamakoro(const char*);

	virtual ~Tamakoro();
	virtual void init(const JMapInfoIter&);
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	void initJointControl();
	bool ringMtxCallBack(TPos3f*, const JointControllerInfo&);
	void updateBindActorMatrix();
	void updateRingUpVec();
	bool requestBind(HitSensor*);
	void requestEndBind();
	void startRide();
	bool requestTutorialEnd();
	bool tryFall();
	bool tryJump();
	bool tryBumpWall();
	bool tryLand();
	bool tryBindStarPointer();
	void reactionCollision();

	void addVelocityOperate();
	void updateRideRail();
	void updateMoment();
	void updateAirTime();
	void updateMarioPose(f32);
	void updateMarioOffset();
	void updateMoveBckBlend(f32);
	void updateSquatBckBlend(f32);
	bool isEnablePushPlayer() const;
	bool isEnableEnemyAttack() const;
	bool isEnableBallBind() const;
	bool isEnableHitCollisionMessage() const;
	bool isUseMarioOffset() const;
	bool isGroundMomentBall() const;
	bool isRideRail() const;
	bool isNeedTutorial() const;
	void startRotateLevelSound();
	void startTamakoroBgm();

	void exeStandByBind();
	void exeBindStart();
	void exeBindStartLand();
	void exeTutorial();
	void exeWait();
	void exeFall();
	void exeJump();
	void exeBumpWall();
	void exeLand();
	void exeFreeze();
	void exeJumpHole();
	void exeJumpHoleSetUp();
	void exeJumpHoleLaunch();
	void exeDashRail();
	void exeDashRailEnd();
	void exeRideRail();
	void exeRideRailFastStart();
	void exeRideRailFast();
	void exeRideRailFastEnd();
	void exeBindEnd();

	SphereAccelSensorController* _90;
	TamakoroTutorial* _94;
	JointController* _98;
	Coin* mPurpleCoin; //0x9C
	TQuat4f _A0;
	TQuat4f _B0;
	TVec3f _C0;
	TVec3f _CC; //Unused?
	TVec3f _D8;
	TVec3f _E4;
	TVec3f _F0;
	TVec3f _FC;
	TVec3f _108;
	TVec3f _114;
	TVec3f _120;
	TVec3f _12C;
	f32 _138;
	f32 _13C;
	f32 _140;
	f32 _144;
	s32 mAirTime;  // 0x148
	s32 _14C;
	AudTamakoroBgmCtrl* mAudioCtrl; //0x150
	bool mForceFastAudio; //0x154
	bool mHasTutorial; //0x155
	bool mIsPurpleCoin; //0x156
};

namespace NrvTamakoro {
	NERVE(TamakoroNrvStandByTutorial);
	NERVE(TamakoroNrvStandByBind);
	NERVE(TamakoroNrvBindStart);
	NERVE(TamakoroNrvBindStartLand);
	NERVE(TamakoroNrvTutorial);
	NERVE(TamakoroNrvWait);
	NERVE(TamakoroNrvFall);
	NERVE(TamakoroNrvJump);
	NERVE(TamakoroNrvBumpWall);
	NERVE(TamakoroNrvLand);
	NERVE(TamakoroNrvFreeze);
	NERVE(TamakoroNrvJumpHole);
	NERVE(TamakoroNrvJumpHoleSetUp);
	NERVE(TamakoroNrvJumpHoleLaunch);
	NERVE(TamakoroNrvDashRail);
	NERVE(TamakoroNrvDashRailEnd);
	NERVE(TamakoroNrvRideRail);
	NERVE(TamakoroNrvRideRailFastStart);
	NERVE(TamakoroNrvRideRailFast);
	NERVE(TamakoroNrvRideRailFastEnd);
	NERVE(TamakoroNrvBindEnd);
}
