#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/Util/JointController.h"
#include "Game/LiveActor/PartsModel.h"
#include "Game/LiveActor/ActorCameraInfo.h"
#include "Game/Camera/CameraTargetMtx.h"
#include "Game/Enemy/AnimScaleController.h"

class DinoPackunTail;
class DinoPackunBall;
class FootPrint;
class DinoPackunEggShell;
class DinoPackunDemoPosition;
class DinoPackunSequencer;

class DinoPackun : public LiveActor {
public:
	DinoPackun(const char*);

	~DinoPackun();
	virtual void init(const JMapInfoIter& rIter);
	virtual void makeActorDead();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPush(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	
	virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	void initTail();
	void initFootPrint();
	void initDemoPosition(const JMapInfoIter&);
	void initEggShell();
	void initBall();
	void initCamera(const JMapInfoIter&);
	void initScaleJointController();
	void startHitReaction();
	bool hitScaleJoint(TPos3f*, const JointControllerInfo&);
	DinoPackunEggShell* getEggShell();
	PartsModel* getEggBrokenModel();
	PartsModel* getBallModel();
	bool attackSensorTail(HitSensor*, HitSensor*);
	bool receiveMsgPlayerAttackTail(u32, HitSensor*, HitSensor*);
	void startSequence();
	void updatePose();
	void updateFootPrintNerve(s32, s32);
	void updateCameraInfo();
	void updateNormalVelocity();
	void updateRunVelocity();
	void appearStarPiece(s32);
	bool isSensorEgg(const HitSensor*) const;
	void resetPosition();
	void adjustTailRootPosition(const TVec3f&, f32);
	void activateParts();
	void onMovementParts();
	void onAimTailBall(s32);
	void offAimTailBall(s32);
	void startDemo();
	void startDemoAndReset();
	void endDemo(const char*);
	void startDamageCamera();
	void endDamageCamera();


	DinoPackunTail* mTail; // 0x90
	DinoPackunBall* mBall; // 0x94
	FootPrint* mFootPrint; // 0x98
	DinoPackunEggShell* mEggShell; // 0x9C
	DinoPackunDemoPosition* mDemoPosition; // 0xA0
	PartsModel* mEggShellBreak; // 0xA4
	PartsModel* mTailBall; // 0xA8
	CameraTargetMtx* mCameraTargetMtx; // 0xAC
	ActorCameraInfo* mActorCameraInfo; // 0xB0
	DinoPackunSequencer* mSequencer; // 0xB4
	JointController* mJointCtrl; // 0xB8
	AnimScaleController* mAnimScaleCtrl; // 0xBC
	TQuat4f _C0; // 0xC0
	TQuat4f _D0; // 0xD0
	TVec3f _E0; // 0xE0
	TVec3f _EC; // 0xEC
	s32 _F8; // 0xF8
	TVec3f mCameraRegisterVec; // 0xFC
	f32 _108; // 0x108
	f32 _10C; // 0x10C
	s32 _110; // 0x110  Camera related
	u8 _114; // 0x114
};