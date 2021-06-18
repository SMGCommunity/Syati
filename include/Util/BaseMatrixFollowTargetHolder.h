#pragma once

#include "JGeometry/TPosition3.h"
#include "JMap/JMapInfoIter.h"

class LiveActor;

class BaseMatrixFollowValidater
{
public:
	bool isValid(s32) const = 0;
};

class BaseMatrixFollower;

class BaseMatrixFollowTarget;

class BaseMatrixFollowTargetHolder;

namespace MR {
	bool isValidFollowID(const JMapInfoIter &);
	void addBaseMatrixFollower(BaseMatrixFollower *);
	void addBaseMatrixFollowTarget(LiveActor *, const JMapInfoIter &, const TPositionMtx *, BaseMatrixFollowValidater *);
};
