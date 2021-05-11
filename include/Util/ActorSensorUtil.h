#pragma once

#include "kamek.h"
#include "JGeometry/TVec3.h"

class LiveActor;
class HitSensor;

namespace MR
{
	HitSensor* addHitSensor(LiveActor *, const char *, u32, u16, f32, const TVec3f &);
	HitSensor* addHitSensorBinder(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorPriorBinder(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorRide(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorMapObj(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorMapObjSimple(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorMapObjMoveCollision(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorEnemy(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorEnemyAttack(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorNpc(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorEye(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorPush(LiveActor *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorPosRide(LiveActor *, const char *, u16, f32, const TVec3f *, const TVec3f &);
	HitSensor* addHitSensorPosMapObj(LiveActor *, const char *, u16, f32, const TVec3f *, const TVec3f &);

	HitSensor* addHitSensorMtx(LiveActor *, const char *, u32, u16, f32, Mtx4 *, const TVec3f &);
	HitSensor* addHitSensorMtxRide(LiveActor *, const char *, u16, f32, Mtx4 *, const TVec3f &);
	HitSensor* addHitSensorMtxEnemy(LiveActor *, const char *, u16, f32, Mtx4 *, const TVec3f &);
	HitSensor* addHitSensorMtxEnemyAttack(LiveActor *, const char *, u16, f32, Mtx4 *, const TVec3f &);
	HitSensor* addHitSensorMtxAnimal(LiveActor *, const char *, u16, f32, Mtx4 *, const TVec3f &);
	HitSensor* addHitSensorAtJoint(LiveActor *, const char *, const char *, u32, u16, f32, const TVec3f &);
	HitSensor* addHitSensorAtJointMapObj(LiveActor *, const char *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorAtJointMapObjSimple(LiveActor *, const char *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorAtJointEnemy(LiveActor *, const char *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorAtJointEnemyAttack(LiveActor *, const char *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorAtJointNpc(LiveActor *, const char *, const char *, u16, f32, const TVec3f &);
	HitSensor* addHitSensorCallback(LiveActor *, const char *, u32, u16, f32);
	HitSensor* addHitSensorCallbackBinder(LiveActor *, const char *, u16, f32);
	HitSensor* addHitSensorCallbackPriorBinder(LiveActor *, const char *, u16, f32);
	HitSensor* addHitSensorCallbackRide(LiveActor *, const char *, u16, f32);
	HitSensor* addHitSensorCallbackMapObj(LiveActor *, const char *, u16, f32);
	HitSensor* addHitSensorCallbackEnemyAttack(LiveActor *, const char *, u16, f32);
	HitSensor* addHitSensorCallbackEye(LiveActor *, const char *, u16, f32);
	HitSensor* addBodyMessageSensor(LiveActor *, u32);
	HitSensor* addBodyMessageSensorReceiver(LiveActor *);
	HitSensor* addBodyMessageSensorMapObj(LiveActor *);
	HitSensor* addBodyMessageSensorMapObjPress(LiveActor *);
	HitSensor* addBodyMessageSensorEnemy(LiveActor *);
	HitSensor* addMessageSensorReceiver(LiveActor *, const char *);

	bool tryUpdateHitSensorsAll(LiveActor *);
	void updateHitSensorsAll(LiveActor *);
	bool isSensorType(HitSensor *, u32);

	// ??? getTaken(const LiveActor *);
	void setSensorPos(HitSensor *, const TVec3f &);

	f32 getSensorRadius(HitSensor *);
	HitSensor* getSensor(LiveActor *, const char *);

	void validateHitSensors(LiveActor *);
	void invalidateHitSensors(LiveActor *);
	void validateHitSensor(HitSensor *);
	void invalidateHitSensor(HitSensor *);
	void validateHitSensor(LiveActor *, const char *);
	void invalidateHitSensor(LiveActor *, const char *);

	void clearHitSensors(LiveActor *);

	HitSensor* getSensor(LiveActor *, int);
	LiveActor* getSensorHost(const HitSensor *);
	bool isSensor(HitSensor const *, const char *);
	bool isSensorPlayer(HitSensor const *);

	bool isSensorBinder(HitSensor const *);

	bool isSensorRide(HitSensor const *);
	bool isSensorPlayerOrRide(HitSensor const *);

	bool isSensorEnemy(HitSensor const *);
	bool isSensorEnemyAttack(HitSensor const *);
	bool isSensorNpc(HitSensor const *);
	bool isSensorMapObj(HitSensor const *);
	bool isSensorAutoRush(HitSensor const *);
	bool isSensorRush(HitSensor const *);
	bool isSensorPressObj(HitSensor const *);
	bool isSensorEye(HitSensor const *);
	bool isSensorPush(HitSensor const *);
	bool isSensorItem(HitSensor const *);

	bool tryGetItem(HitSensor *, HitSensor *);
	TVec3f* getSensorPos(const HitSensor *);
	TVec3f* getSensorPos(const LiveActor *, const char *);

	void calcSensorDirectionNormalize(TVec3f *, const HitSensor *, const HitSensor *);

	void calcSensorHorizonNormalize(TVec3f *, const TVec3f &, const HitSensor *, const HitSensor *);
	HitSensor* getMessageSensor();
	bool sendArbitraryMsg(u32, HitSensor *, HitSensor *);
	bool sendMsgPush(HitSensor *, HitSensor *);

	bool sendMsgPlayerTrample(HitSensor *, HitSensor *);
	bool sendMsgPlayerPunch(HitSensor *, HitSensor *);

	bool sendMsgJump(HitSensor *, HitSensor *);
	bool sendMsgTouchJump(HitSensor *, HitSensor *);
	bool sendMsgTaken(HitSensor *, HitSensor *);
	bool sendMsgAwayJump(HitSensor *, HitSensor *);

	bool sendMsgEnemyAttackMsgToDir(u32, HitSensor *, HitSensor *, const TVec3f &);

	bool sendMsgEnemyAttackFlipWeak(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlipWeakJump(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlip(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlipToDir(HitSensor *, HitSensor *, const TVec3f &);
	bool sendMsgEnemyAttackFlipJump(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlipRot(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFlipMaximumToDir(HitSensor *, HitSensor *, const TVec3f &);
	bool sendMsgEnemyAttack(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackOrPush(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackStrong(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackStrongOrPush(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackStrongToDir(HitSensor *, HitSensor *, const TVec3f &);
	bool sendMsgEnemyAttackFire(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFireStrong(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackElectric(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackFreeze(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackExplosion(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackCounterSpin(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackCounterHipDrop(HitSensor *, HitSensor *);
	bool sendMsgLockOnStarPieceShoot(HitSensor *, HitSensor *);
	bool sendMsgStarPieceAttack(HitSensor *, HitSensor *);
	bool sendMsgStarPieceGift(HitSensor *, HitSensor *, u32);
	bool sendMsgEnemyAttackMaximum(HitSensor *, HitSensor *);
	bool sendMsgEnemyAttackMaximumToDir(HitSensor *, HitSensor *, const TVec3f &);

	bool sendMsgToBindedSensor(u32, HitSensor *);
	bool sendMsgToGroundSensor(u32, HitSensor *);
	bool sendMsgToWallSensor(u32, HitSensor *);
	bool sendMsgToRoofSensor(u32, HitSensor *);

	bool sendMsgToEnemyAttackBlow(HitSensor *, HitSensor *);

	bool sendMsgToEnemyAttackTrample(HitSensor *, HitSensor *);

	bool sendMsgToEnemyAttackShockWave(HitSensor *, HitSensor *);
	bool sendMsgToAllLiveActor(u32, LiveActor *);
	bool sendMsgToGroupMember(u32, LiveActor *, HitSensor *, const char *);

	bool sendMsgExplosionToNearActor(HitSensor *, f32);
	bool isInSpinStormRange(u32, HitSensor *, HitSensor *, f32);
	void receiveItemShowMsg(u32, HitSensor *, HitSensor *);
	void receiveItemHideMsg(u32, HitSensor *, HitSensor *);
	void getGroundSensor(const LiveActor *);
	void getRoofSensor(const LiveActor *);
	void getWallSensor(const LiveActor *);

	bool isMsgPlayerHitAll(u32);

	bool isMsgPlayerSpinAttack(u32);
	bool isMsgPlayerSpinAttackOrSupportTico(u32);
	bool isMsgPlayerTrample(u32);
	bool isMsgPlayerHipDrop(u32);
	bool isMsgPlayerHipDropFloor(u32);
	bool isMsgPlayerUpperPunch(u32);
	bool isMsgPlayerKick(u32);
	bool isMsgGoldenTurtleAttack(u32);

	bool isMsgJetTurtleAttack(u32);

	bool isMsgFireBallAttack(u32);
	bool isMsgSearchlightAttack(u32);
	bool isMsgFreezeAttack(u32);
	bool isMsgInvincibleAttack(u32);

	bool isMsgSupportTicoSpin(u32);
	bool isMsgAutoRushBegin(u32);

	bool isMsgUpdateBaseMtx(u32);

	bool isMsgRushCancel(u32);

	bool isMsgIsRushTakeOver(u32);
	bool isMsgFloorTouch(u32);
	bool isMsgWallTouch(u32);

	bool isMsgItemGet(u32);
	bool isMsgItemPull(u32);
	bool isMsgItemShow(u32);
	bool isMsgItemHide(u32);

	bool isMsgItemEndMove(u32);

	bool isMsgInhaleBlackHole(u32);

	bool isMsgEnemyAttack(u32);
	bool isMsgEnemyAttackFire(u32);
	bool isMsgEnemyAttackFireStrong(u32);
	bool isMsgEnemyAttackElectric(u32);
	bool isMsgExplosionAttack(u32);
	bool isMsgToEnemyAttackBlow(u32);

	bool isMsgToEnemyAttackTrample(u32);

	bool isMsgToEnemyAttackShockWave(u32);
	bool isMsgSpinStormRange(u32);

	bool isMsgRaceReady(u32);
	bool isMsgRaceStart(u32);
	bool isMsgRaceReset(u32);
	bool isMsgLockOnStarPieceShoot(u32);
	bool isMsgBallDashWall(u32);
	bool isMsgBallDashGround(u32);
	bool isMsgStartPowerStarGet(u32);
	bool isMsgTouchPlantItem(u32);
	bool isMsgHitmarkEmit(u32);
	bool isMsgStarPieceAttack(u32);
	bool isMsgStarPieceReflect(u32);
	bool isMsgStarPieceGift(u32);
};
