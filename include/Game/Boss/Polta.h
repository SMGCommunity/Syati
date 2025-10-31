#pragma once

#include "Game/LiveActor/ActorCameraInfo.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ModelObj.h"

class PoltaSensorCtrl;
class PoltaArm;
class PoltaActionSequencer;
class BombTeresaHolder;
class PoltaRockHolder;
class PoltaGroundRockHolder;

class Polta : public LiveActor {
public:
	Polta(const char*);

	virtual ~Polta();
	virtual void init(const JMapInfoIter& rIter);
	virtual void calcAnim();
	virtual void makeActorAppeared();
	virtual void kill();
	virtual void makeActorDead();
	virtual void control();
	virtual void calcAndSetBaseMtx();
	virtual void attackSensor(HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgPlayerAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveMsgEnemyAttack(u32 msg, HitSensor* pSender, HitSensor* pReceiver);
	virtual bool receiveOtherMsg(u32 msg, HitSensor* pSender, HitSensor* pReceiver);

	void initArm();
	void initPartsModel();
	void initSensor();
	void initBombTeresaHolder();
	void initCamera();
	void appearBreakModel(const TVec3f&, const char*);
	void appearBreakModelFirst(const TVec3f&);
	void appearBreakModelMiddle(const TVec3f&);
	void appearBreakModelLast(const TVec3f&);
	void appearStarPiece(s32);
	bool isEndBreakModel() const;
	void killBreakModel();
	void rotateToPlayer();
	void calcToPlayerRotateSpeed() const;
	void updateAction();
	void updatePose(f32, f32);
	void start();
	void setStartPose();

	PoltaSensorCtrl* mSensorCtrl;             // 0x90
	PoltaArm* mLeftArm;                       // 0x94
	PoltaArm* mRightArm;                      // 0x98
	PoltaActionSequencer* mSequencer;         // 0x9C
	BombTeresaHolder* mBombTeresaHolder;      // 0xA0
	PoltaRockHolder* mRockHolder;             // 0xA4
	PoltaGroundRockHolder* mGroundRockHolder; // 0xA8
	ActorCameraInfo* mCameraInfo;             // 0xAC
	ModelObj* mBreakModel;                    // 0xB0
	ModelObj* mFormationModel;                // 0xB4
	TQuat4f _B8;                              // 0xB8
	TVec3f _C8;                               // 0xC8
	TQuat4f _D4;                              // 0xD4
	TVec3f _E4;                               // 0xE4
	f32 _F0;                                  // 0xF0
};