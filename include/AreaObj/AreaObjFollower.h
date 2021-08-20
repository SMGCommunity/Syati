#pragma once

#include "AreaObj/AreaObj.h"
#include "Util/BaseMatrixFollowTargetHolder.h"

class AreaObjFollower : public BaseMatrixFollower
{
public:
	AreaObjFollower(AreaObj *pArea, const JMapInfoIter &rIter);

	virtual void update();

	Mtx mFollowMtx; // _14
	AreaObj* mFollowerArea; // _44
};

namespace MR
{
	bool addBaseMatrixFollowerAreaObj(AreaObj *pArea, const JMapInfoIter &rIter);
};
