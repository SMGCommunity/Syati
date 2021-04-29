#pragma once

#include "JGeometry/TPosition3.h"
#include "JGeometry/TMatrix34.h"
#include "JMap/JMapInfoIter.h"

class BaseMatrixFollowValidater;
class LiveActor;

namespace MR {
	void addBaseMatrixFollowTarget(LiveActor*, const JMapInfoIter&, const JGeometry::TPosition3<JGeometry::TMatrix34<JGeometry::SMatrix34C<f32> > >*, BaseMatrixFollowValidater*);
};
