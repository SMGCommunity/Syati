#pragma once

#include "Gravity/PlanetGravity.h"
#include "LiveActor/Rail/RailRider.h"

class GravityCreator
{
public:
	GravityCreator();

	virtual PlanetGravity* getGravity() = 0;
	virtual PlanetGravity* createInstance() = 0;
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);
	virtual void settingFromJMapArgs(s32, s32, s32);
	virtual void settingFromJMapOtherParam(const JMapInfoIter &);

	void createFromJMap(const JMapInfoIter &);
};

class BarrelGravityCreator : public GravityCreator
{
public:
	inline BarrelGravityCreator() : GravityCreator(), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);
	virtual void settingFromJMapArgs(s32, s32, s32);

	PlanetGravity* mGravityInstance; // _4
};

class CubeGravityCreator : public GravityCreator
{
public:
	inline CubeGravityCreator() : GravityCreator(), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);

	PlanetGravity* mGravityInstance; // _4
};

class DiskGravityCreator : public GravityCreator
{
public:
	inline DiskGravityCreator() : GravityCreator(), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);
	virtual void settingFromJMapArgs(s32, s32, s32);

	PlanetGravity* mGravityInstance; // _4
};

class DiskTorusCreatorGravityCreator : public GravityCreator
{
public:
	inline DiskTorusCreatorGravityCreator() : GravityCreator(), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);
	virtual void settingFromJMapArgs(s32, s32, s32);

	PlanetGravity* mGravityInstance; // _4
};

class ConeGravityCreator : public GravityCreator
{
public:
	inline ConeGravityCreator() : GravityCreator(), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);
	virtual void settingFromJMapArgs(s32, s32, s32);

	PlanetGravity* mGravityInstance; // _4
};

class PlaneGravityCreator : public GravityCreator
{
public:
	inline PlaneGravityCreator() : GravityCreator(), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);

	PlanetGravity* mGravityInstance; // _4
};

class PlaneInBoxGravityCreator : public GravityCreator
{
public:
	inline PlaneInBoxGravityCreator() : GravityCreator(), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);
	virtual void settingFromJMapArgs(s32, s32, s32);

	PlanetGravity* mGravityInstance; // _4
};

class PlaneInCylinderGravityCreator : public GravityCreator
{
public:
	inline PlaneInCylinderGravityCreator() : GravityCreator(), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);
	virtual void settingFromJMapArgs(s32, s32, s32);

	PlanetGravity* mGravityInstance; // _4
};

class PlaneZeroGravityCreator : public PlaneGravityCreator
{
public:
	inline PlaneZeroGravityCreator() : PlaneGravityCreator() {
		mGravityInstance = NULL;
	}

	virtual PlanetGravity* createInstance();
};

class PlaneZeroInBoxGravityCreator : public PlaneInBoxGravityCreator
{
public:
	inline PlaneZeroInBoxGravityCreator() : PlaneInBoxGravityCreator() {
		mGravityInstance = NULL;
	}

	virtual PlanetGravity* createInstance();
};

class PlaneZeroInCylinderGravityCreator : public PlaneInCylinderGravityCreator
{
public:
	inline PlaneZeroInCylinderGravityCreator() : PlaneInCylinderGravityCreator() {
		mGravityInstance = NULL;
	}

	virtual PlanetGravity* createInstance();
};

class PointGravityCreator : public GravityCreator
{
public:
	inline PointGravityCreator() : GravityCreator(), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);

	PlanetGravity* mGravityInstance; // _4
};

class SegmentGravityCreator : public GravityCreator
{
public:
	inline SegmentGravityCreator() : GravityCreator(), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromSRT(const TVec3f &, const TVec3f &, const TVec3f &);
	virtual void settingFromJMapArgs(s32, s32, s32);

	PlanetGravity* mGravityInstance; // _4
};

class WireGravityCreator : public GravityCreator
{
public:
	inline WireGravityCreator() : GravityCreator(), mRailRider(NULL), mGravityInstance(NULL) {}

	virtual PlanetGravity* getGravity();
	virtual PlanetGravity* createInstance();
	virtual void settingFromJMapOtherParam(const JMapInfoIter &);

	RailRider* mRailRider; // _4
	PlanetGravity* mGravityInstance; //_8
};
