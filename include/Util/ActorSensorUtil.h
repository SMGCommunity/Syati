#pragma once

#include "kamek.h"
#include "JGeometry/TVec3.h"

class LiveActor;
class HitSensor;

namespace MR
{
	HitSensor* getSensor(LiveActor *, const char *);
	void addBodyMessageSensorMapObj(LiveActor *);
	HitSensor* addHitSensorMapObj(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	HitSensor* addHitSensorMapObjMoveCollision(LiveActor *, const char *, u16, f32, const JGeometry::TVec3<f32> &);
	void addBodyMessageSensor(LiveActor *, u32);
	
	void addHitSensor(LiveActor *, const char *, u32, u16, float, const JGeometry::TVec3<f32> &);
	
	bool isSensorPlayer(const HitSensor *);
	void sendMsgPush(HitSensor *, HitSensor *);
	
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