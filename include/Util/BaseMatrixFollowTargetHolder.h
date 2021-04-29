#pragma once

#include "JGeometry/TPosition3.h"
#include "JMap/JMapInfoIter.h"

class BaseMatrixFollowValidater;
class LiveActor;

namespace MR {
	void addBaseMatrixFollowTarget(LiveActor *, const JMapInfoIter &, const TPositionMtx *, BaseMatrixFollowValidater *);
};
