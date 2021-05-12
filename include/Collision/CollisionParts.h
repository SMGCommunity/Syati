#pragma once

#include "Actor/Sensor/HitSensor.h"
#include "JGeometry/TPosition3.h"
#include "JGeometry/TVec3.h"

class Triangle;
class TriangleFilterBase;

class CollisionParts
{
	CollisionParts();

	// unknown function here
	void init(const TPositionMtx &, HitSensor *, const void *, const void *, s32, bool);
	void addToBelongZone();
	void removeFromBelongZone();
	void initWithAutoEqualScale(const TPositionMtx &, HitSensor *, const void *, const void *, s32, bool);
	void initWithNotUsingScale(const TPositionMtx &, HitSensor *, const void *, const void *, s32, bool);
	void resetAllMtx(const TPositionMtx &);
	void resetAllMtx();
	void resetAllMtxPrivate(const TPositionMtx &);
	void setMtx(const TPositionMtx &);
	void setMtx();
	void updateMtx();
	void makeEqualScale(Mtx4 *);
	void updateBoundingSphereRange();
	void updateBoundingSphereRange(TVec3f);
	void updateBoundingSphereRangePrivate(f32);
	//void checkStrikePoint(HitInfo *, const TVec3f &);
	//void checkStrikeBall(HitInfo *, u32, const TVec3f &, f32, bool, const TriangleFilterBase *);
	//void checkStrikeBallCore(HitInfo *, u32, const TVec3f &, const TVec3f &, f32, f32, f32, KC_PrismData **, f32 *, u8 *, const TriangleFilterBase *, const TVec3f *);
	//void checkStrikeBallWithThickness(HitInfo *, u32, const TVec3f &, f32, f32, const TriangleFilterBase *);
	//void calcCollidePosition(TVec3f *, const KC_PrismData &, u8);
	void projectToPlane(TVec3f *, const TVec3f &, const TVec3f &, const TVec3f &);
	//void checkStrikeLine(HitInfo *, u32, const TVec3f &, const TVec3f &, const TriangleFilterBase *);
	void createAreaPolygonList(Triangle *, u32, const TVec3f &, const TVec3f &);
	void createAreaPolygonListArray(Triangle *, u32, TVec3f *, u32);
	void calcForceMovePower(TVec3f *, const TVec3f &) const;

	s32 _0;
	Mtx _4;
	Mtx _34;
	Mtx _64;
	Mtx _94;
	u32* _C4; // KCollisionServer
	s32 _C8;
	u8 _CC;
	u8 _CD;
	u8 _CE;
	u8 _CF;
	u8 _D0;
	s32 _D4;
	f32 _D8;
	f32 _DC;
	s32 _E0;
	s32 _E4;
	f32 _E8; // TVec3f?
	f32 _EC;
	f32 _E0;
};
