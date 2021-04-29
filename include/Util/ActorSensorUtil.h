#pragma once

#include "kamek.h"
#include "JGeometry/TVec3.h"

class LiveActor;
class HitSensor;

namespace MR
{
	HitSensor* addHitSensor(LiveActor *, const char *, u32, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorBinder(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorPriorBinder(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorRide(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorMapObj(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorMapObjSimple(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorMapObjMoveCollision(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorEnemy(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorEnemyAttack(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorNpc(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorEye(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorPush(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorPosRide(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32>*);
	HitSensor* addHitSensorPosMapObj(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32>*);

	HitSensor* addHitSensorMtx(LiveActor *, const char *, u32, u16, f32, Mtx, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorMtxRide(LiveActor *, const char *, u16, f32, Mtx, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorMtxEnemy(LiveActor *, const char *, u16, f32, Mtx, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorMtxEnemyAttack(LiveActor *, const char *, u16, f32, Mtx, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorMtxAnimal(LiveActor *, const char *, u16, f32, Mtx, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorAtJoint(LiveActor *, const char *, const char *, u32, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorAtJointMapObj(LiveActor *, const char *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorAtJointMapObjSimple(LiveActor *, const char *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorAtJointEnemy(LiveActor *, const char *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorAtJointEnemyAttack(LiveActor *, const char *, const char *, u16, f32, const JGeometry::TVec3<f32> &);

	void addBodyMessageSensor(LiveActor *, u32);

	void addBodyMessageSensorMapObj(LiveActor *);

	void invalidateHitSensors(LiveActor *);

	void validateHitSensor(LiveActor *, const char *);
	void invalidateHitSensor(LiveActor *, const char *);
	
	bool isSensorPlayer(const HitSensor *);
	bool isSensorBinder(const HitSensor *);

	bool isSensorRide(const HitSensor *);
	bool isSensorPlayerOrRide(const HitSensor *);

	bool isSensorEnemy(const HitSensor *);
	bool isSensorEnemyAttack(const HitSensor *);
	bool isSensorNPC(const HitSensor *);
	bool isSensorMapObj(const HitSensor *);

	bool isSensorItem(const HitSensor *);

	HitSensor* getSensor(LiveActor *, const char *);

	void sendMsgPush(HitSensor *, HitSensor *);

	void sendMsgEnemyAttack(HitSensor *, HitSensor *);

	void sendMsgEnemyAttackElectric(HitSensor *, HitSensor *);
	void sendMsgEnemyAttackFreeze(HitSensor *, HitSensor *);
	void sendMsgEnemyAttackExplosion(HitSensor *, HitSensor *);

	void sendMsgToGroupMember(u32, LiveActor *, HitSensor *, const char *);
	
	bool isMsgPlayerHitAll(u32);
	bool isMsgPlayerSpinAttack(u32);
	// I believe this one is for when the player stomps on something
	bool isMsgPlayerTrample(u32);
	bool isMsgPlayerHipDrop(u32);
	bool isMsgPlayerHipDropFloor(u32);
	bool isMsgPlayerUpperPunch(u32);
	bool isMsgPlayerKick(u32);

	bool isMsgJetTurtleAttack(u32);

	bool isMsgFireBallAttack(u32);
	bool isMsgSearchlightAttack(u32); //Located at 0x80016C40 USA.
	bool isMsgFreezeAttack(u32);
	bool isMsgInvincibleAttack(u32);

	bool isMsgAutoRushBegin(u32);
	bool isMsgUpdateBaseMtx(u32);
	bool isMsgRushCancel(u32);
	bool isMsgIsRushTakeOver(u32);

	bool isMsgFloorTouch(u32);
	bool isMsgWallTouch(u32);
	bool isMsgCeilTouch(u32);
	bool isMsgItemGet(u32);
	bool isMsgItemPull(u32);
	bool isMsgItemShow(u32);
	bool isMsgItemHide(u32);

	bool isMsgInhaleBlackHole(u32);

	bool isMsgEnemyAttack(u32);
	bool isMsgEnemyAttackFire(u32);
	bool isMsgEnemyAttackFireStrong(u32);
	bool isMsgEnemyAttackElectric(u32);
	bool isMsgExplosionAttack(u32);
	bool isMsgLockOnStarPieceShoot(u32);
	bool isMsgBallDashWall(u32);
	bool isMsgBallDashGround(u32);
	bool isMsgStarPieceAttack(u32);
	bool isMsgStarPieceReflect(u32);
	bool isMsgStarPieceGift(u32);
};
