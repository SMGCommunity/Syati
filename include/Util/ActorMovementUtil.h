#pragma once

#include "JGeometry/TPosition3.h"
#include "JGeometry/TQuat4.h"
#include "JGeometry/TVec3.h"
#include "kamek.h"

class HitSensor;
class LiveActor;

namespace MR
{
	f32 calcDistance(const HitSensor *, const HitSensor *, TVec3f *);

	f32 calcDistanceHorizontal(const LiveActor *, const TVec3f &, const TVec3f &);
	f32 calcDistanceHorizontal(const LiveActor *, const TVec3f &);
	f32 calcDistanceVertical(const LiveActor *, const TVec3f &, const TVec3f &);
	f32 calcDistanceVertical(const LiveActor *, const TVec3f &);
	f32 calcDistanceToPlayer(const LiveActor *);
	f32 calcDistanceToPlayerH(const LiveActor *);

	bool isNear(const HitSensor *, const HitSensor *, f32);
	bool isNear(const LiveActor *, const LiveActor *, f32);
	bool isNear(const LiveActor *, const TVec3f &, f32);
	bool isNearPlayer(const LiveActor *, f32);
	bool isNearPlayerAnyTime(const LiveActor *, f32);
	bool isNearPlayer(const TVec3f &, f32);
	bool isNearPlayerPose(const LiveActor *, f32, f32);

	void calcFrontVec(TVec3f *, const LiveActor *);
	void calcUpVec(TVec3f *, const LiveActor *);
	void calcSideVec(TVec3f *, const LiveActor *);

	void calcVecToPlayerH(TVec3f *, const LiveActor *, const TVec3f *);
	void calcVecFromPlayerH(TVec3f *, const LiveActor *);

	void calcVecToTargetPosH(TVec3f *, const LiveActor *, const TVec3f &, const TVec3f *);
	void calcVecFromTargetPosH(TVec3f *, const LiveActor *, const TVec3f &, const TVec3f *);

	bool isFaceToTargetDegree(const LiveActor *, const TVec3f &, const TVec3f &, f32);
	bool isFaceToPlayerDegree(const LiveActor *, const TVec3f &, f32);
	bool isFaceToTargetDegree(const LiveActor *, const TVec3f &, f32);
	bool isFaceToPlayerDegree(const LiveActor *, f32);
	bool isFaceToPlayerDegreeHV(const LiveActor *, const TVec3f &, f32, f32);
	bool isFaceToTargetHorizontalDegree(const LiveActor *, const TVec3f &, const TVec3f &, f32);
	bool isFaceToPlayerHorizontalDegree(const LiveActor *, const TVec3f &, f32);
	bool isClockwiseToDir(const LiveActor *, const TVec3f &, const TVec3f &);
	bool isClockwiseToPlayer(const LiveActor *, const TVec3f &);
	bool isPlayerLeftSide(const LiveActor *);
	bool isLeftSideFromPlayer(const LiveActor *);
	bool isInSightConePlayer(const LiveActor *, const TVec3f &, f32, f32);
	bool isInSightFanPlayer(const LiveActor *, const TVec3f &, f32, f32, f32);
	bool isOnPlayer(const LiveActor *);
	bool isPlayerExistSide(const LiveActor *, f32, f32);
	bool isPlayerExistUp(const LiveActor *, f32, f32);
	bool isPlayerExistDown(const LiveActor *, f32, f32);
	bool isInWater(const LiveActor *, const TVec3f &);
	bool isInDeath(const LiveActor *, const TVec3f &);

	void makeMtxTR(Mtx4*, const LiveActor *);
	void makeMtxTRS(Mtx4*, const LiveActor *);
	void makeMtxTransRotateY(Mtx4*, const LiveActor *);

	void calcMtxFromGravityAndZAxis(TPositionMtx *, const LiveActor *, const TVec3f &, const TVec3f &);

	void calcActorAxis(TVec3f *, TVec3f *, TVec3f *, const LiveActor *);
	void calcActorAxisY(TVec3f *, const LiveActor *);
	void calcActorAxisZ(TVec3f *, const LiveActor *);
	void faceToVector(TQuat4f *, TVec3f, f32);
	void faceToVector(Mtx4*, TVec3f, f32);
	void faceToPoint(Mtx4*, TVec3f, f32);

	void makeQuatFromRotate(TQuat4f *, const LiveActor *);
	void makeQuatAndFrontFromRotate(TQuat4f *, TVec3f *, const LiveActor *);

	void blendQuatFromGroundAndFront(TQuat4f *, const LiveActor *, const TVec3f &, f32, f32);

	void resetPosition(LiveActor *);
	void resetPosition(LiveActor *, const TVec3f &);
	void resetPosition(LiveActor *, const char *);
	void makeMtxOnMapCollision(TPositionMtx *, LiveActor *, f32);

	void addVelocityJump(LiveActor *, f32);
	void addVelocityLimit(LiveActor *, const TVec3f &);
	void setVelocityJump(LiveActor *, f32);
	void addVelocityToGravity(LiveActor *, f32);
	void addVelocityToGravityOrGround(LiveActor *, f32);
	void addVelocityToCollisionNormal(LiveActor *, f32);
	void addVelocityKeepHeight(LiveActor *, const TVec3f &, f32, f32);
	void addVelocityKeepHeightUseShadow(LiveActor *, f32, f32, f32, const char *);
	void addVelocityKeepHeightUseShadow(LiveActor *, f32, f32, f32, f32, const char *);
	void addVelocitySeparateHV(LiveActor *, const TVec3f &, f32, f32);
	void setVelocitySeparateHV(LiveActor *, const TVec3f &, f32, f32);
	void attenuateVelocityExceptDirection(LiveActor *, const TVec3f &, f32);
	void restrictVelocity(LiveActor *, f32);
	void killVelocityOnGroundH(LiveActor *);
	void killVelocityOnGroundCosH(LiveActor *, f32);
	void killVelocityToTarget(LiveActor *, const TVec3f &);

	void forceBindOnGround(LiveActor *, f32, f32);

	void reboundVelocityFromEachCollision(LiveActor *, f32, f32, f32, f32);
	void reboundVelocityFromCollision(LiveActor *, f32, f32, f32);
	void zeroVelocity(LiveActor *);
	void setVelocity(LiveActor *, const TVec3f &);
	void addVelocity(LiveActor *, const TVec3f &);
	void attenuateVelocity(LiveActor *, f32);
	f32 calcVelocityLength(const LiveActor *);

	f32 calcGravitySpeed(const LiveActor *);

	void applyVelocityDampAndGravity(LiveActor *, f32, f32, f32, f32, f32);

	void sendMsgPushAndKillVelocityToTarget(LiveActor *, HitSensor *, HitSensor *);
	void addVelocityFromPush(LiveActor *, f32, HitSensor *, HitSensor *);
	void addVelocityFromPushHorizon(LiveActor *, f32, HitSensor *, HitSensor *);
	void addVelocitySeparateHV(LiveActor *, HitSensor *, HitSensor *, f32, f32);
	void setVelocitySeparateHV(LiveActor *, HitSensor *, HitSensor *, f32, f32);
	void addVelocitySeparateHV(LiveActor *, HitSensor *, HitSensor *, f32, f32);
	void setVelocitySeparateHV(LiveActor *, HitSensor *, HitSensor *, f32, f32);

	void reflectVelocityH(LiveActor *, HitSensor *, HitSensor *, f32);
	void calcVelocityAreaMoveOnGround(TVec3f *, const LiveActor *);
	void calcVelocityRailMoveOnGround(TVec3f *, const LiveActor *);
	void calcVelocityAreaOrRailMoveOnGround(TVec3f *, const LiveActor *);

	void turnDirection(const LiveActor *, TVec3f *, const TVec3f &, f32);
	void turnDirectionDegree(const LiveActor *, TVec3f *, const TVec3f &, f32);
	void turnDirectionToTarget(const LiveActor *, TVec3f *, const TVec3f &, f32);
	void turnDirectionToTargetDegree(const LiveActor *, TVec3f *, const TVec3f &, f32);
	void turnDirectionToTargetDegreeHorizon(const LiveActor *, TVec3f *, const TVec3f &, f32);
	void turnDirectionToTargetUseGroundNormalDegree(const LiveActor *, TVec3f *, const TVec3f &, f32);

	void moveAndTurnToDirection(LiveActor *, TVec3f *, const TVec3f &, f32, f32, f32, f32);
	void moveAndTurnToTarget(LiveActor *, TVec3f *, const TVec3f &, f32, f32, f32, f32);
	void moveAndTurnToPlayer(LiveActor *, TVec3f *, f32, f32, f32, f32);

	void flyAndTurnAlongRailSearchingPlayer(LiveActor *, TVec3f *, f32, f32, f32, f32, f32, bool);
	void escapeFromPlayer(LiveActor *, TVec3f *, f32, f32, f32, f32);
	void calcRotate(LiveActor *, const TVec3f &, f32);
	void moveAndTurnToDirection(LiveActor *, const TVec3f &, f32, f32, f32, f32);
	void moveAndTurnToTarget(LiveActor *, const TVec3f &, f32, f32, f32, f32);
	void moveAndTurnToPlayer(LiveActor *, f32, f32, f32, f32);
	void moveAndTurnAlongRail(LiveActor *, f32, f32, f32, f32, f32, bool *);
};
