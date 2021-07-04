#pragma once

#include "Gravity/GlobalGravityObj.h"
#include "Util/BaseMatrixFollowTargetHolder.h"

class GravityFollower : public BaseMatrixFollower
{
	GravityFollower(GlobalGravityObj *, const JMapInfoIter &);

	virtual void setGravityFollowHost(const NameObj *);
	virtual void update();

	PlanetGravity* mGravity; // _14
};

namespace MR
{
	bool addBaseMatrixFollowerGravity(GlobalGravityObj *, const JMapInfoIter &);
};
