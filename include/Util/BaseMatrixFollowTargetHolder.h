#pragma once

#include "JGeometry/TPosition3.h"
#include "NameObj/NameObj.h"

class LiveActor;

class BaseMatrixFollowValidater
{
public:
	bool isValid(s32) const = 0;
};

class BaseMatrixFollowTarget;

class BaseMatrixFollower
{
public:
	BaseMatrixFollower(NameObj *, const JMapInfoIter &);

	virtual void setGravityFollowHost(const NameObj *);
	virtual void update();

	NameObj* getFollowTargetActor() const;
	void calcFollowMatrix(TPositionMtx *) const;
	bool isEnableFollow() const;
	bool isValid() const;

	JMapLinkInfo* mLinkInfo; // _4
	NameObj* mHost; // _8
	BaseMatrixFollowTarget* mTarget; // _C
	s32 _10;
};

class BaseMatrixFollowTarget;

class BaseMatrixFollowTargetHolder;

namespace MR {
	bool isValidFollowID(const JMapInfoIter &);
	void addBaseMatrixFollower(BaseMatrixFollower *);
	void addBaseMatrixFollowTarget(LiveActor *, const JMapInfoIter &, const TPositionMtx *, BaseMatrixFollowValidater *);
};
