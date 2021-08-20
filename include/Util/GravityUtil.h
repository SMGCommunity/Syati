#pragma once

#include "JSystem.h"

class GravityInfo;
class LiveActor;
class NameObj;
class PlanetGravity;

// Complete
void getJMapInfoArgPlus(const JMapInfoIter &, const char *, f32 *);
void getJMapInfoArgPlus(const JMapInfoIter &, const char *, s32 *);
void calcGravityVectorOrZero(const NameObj *, const TVec3f &, u32, TVec3f *, GravityInfo *, u32);

namespace MR
{
	void registerGravity(PlanetGravity *);

	void calcGravityVector(const LiveActor *, TVec3f *, GravityInfo *, u32);
	void calcGravityVector(const NameObj *, const TVec3f &, TVec3f *, GravityInfo *, u32);
	void calcDropShadowVector(const LiveActor *, TVec3f *, GravityInfo *, u32);
	void calcDropShadowVector(const NameObj *, const TVec3f &, TVec3f *, GravityInfo *, u32);
	void calcGravityAndDropShadowVector(const LiveActor *, TVec3f *, GravityInfo *, u32);
	void calcGravityVectorOrZero(const LiveActor *, TVec3f *, GravityInfo *, u32);
	void calcGravityVectorOrZero(const NameObj *, TVec3f *, GravityInfo *, u32);
	void calcGravityVectorOrZero(const NameObj *, const TVec3f &, TVec3f *, GravityInfo *, u32);
	void calcDropShadowVectorOrZero(const NameObj *, const TVec3f &, TVec3f *, GravityInfo *, u32);
	void calcGravityAndDropShadowVectorOrZero(const LiveActor *, const TVec3f &, TVec3f *, GravityInfo *, u32);
	void calcAttractMarioLauncherOrZero(const LiveActor *, TVec3f *, GravityInfo *, u32);

	bool isZeroGravity(const LiveActor *);
	bool isLightGravity(const GravityInfo &);
	
	void getJMapInfoGravityType(const JMapInfoIter &, PlanetGravity *);
	void getJMapInfoGravityPower(const JMapInfoIter &, PlanetGravity *);
	void settingGravityParamFromJMap(PlanetGravity *, const JMapInfoIter &);
};
