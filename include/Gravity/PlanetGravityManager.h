#pragma once

#include "Gravity/GravityInfo.h"

class PlanetGravityManager : public NameObj
{
public:
	PlanetGravityManager(const char*);

	virtual ~PlanetGravityManager();
	virtual void init(const JMapInfoIter &);

	void calcTotalGravityVector(TVec3f *, GravityInfo *, const TVec3f &, u32 gravityType, u32, const NameObj *) const;
	void registerGravity(PlanetGravity *);

	PlanetGravity* mGravities[128];
	s32 mNumGravities;
};
