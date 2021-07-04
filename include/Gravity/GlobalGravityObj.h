#pragma once

#include "Gravity/GravityCreator.h"
#include "LiveActor/LiveActor.h"

class GlobalGravityObj : public LiveActor
{
public:
	GlobalGravityObj(const char*);

	~GlobalGravityObj();

	virtual void init(const JMapInfoIter &);
	virtual void movement();
	virtual void makeActorAppeared();
	virtual void makeActorDead();

	void updateSwitch();
	PlanetGravity* getGravity();

	GravityCreator* mCreator; // _90
};

namespace MR
{
	GlobalGravityObj* createGlobalBarrelGravityObj(const char *);
	GlobalGravityObj* createGlobalCubeGravityObj(const char *);
	GlobalGravityObj* createGlobalConeGravityObj(const char *);
	GlobalGravityObj* createGlobalDiskGravityObj(const char *);
	GlobalGravityObj* createGlobalDiskTorusGravityObj(const char *);
	GlobalGravityObj* createGlobalPlaneGravityObj(const char *);
	GlobalGravityObj* createGlobalPlaneInBoxGravityObj(const char *);
	GlobalGravityObj* createGlobalPlaneInCylinderGravityObj(const char *);
	GlobalGravityObj* createGlobalPointGravityObj(const char *);
	GlobalGravityObj* createGlobalSegmentGravityObj(const char *);
	GlobalGravityObj* createGlobalWireGravityObj(const char *);
	GlobalGravityObj* createZeroGravitySphereObj(const char *);
	GlobalGravityObj* createZeroGravityBoxObj(const char *);
	GlobalGravityObj* createZeroGravityCylinderObj(const char *);
};
