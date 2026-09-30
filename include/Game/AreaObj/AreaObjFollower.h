#pragma once

#include "Game/AreaObj/AreaObj.h"
#include "Game/Util/BaseMatrixFollowTargetHolder.h"

/* FINISHED */

class AreaObjFollower : public BaseMatrixFollower {
public:
	AreaObjFollower(AreaObj *pArea, const JMapInfoIter &rIter);

	virtual void update();

	/* 0x14 */ TPos3f mFollowMtx;
	/* 0x44 */ AreaObj* mFollowerArea;
};

namespace MR {
	bool addBaseMatrixFollowerAreaObj(AreaObj *pArea, const JMapInfoIter &rIter);
}
