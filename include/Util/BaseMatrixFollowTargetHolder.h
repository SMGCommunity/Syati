#pragma once

#include "JGeometry/TPosition3.h"
#include "JMap/JMapInfoIter.h"
#include "Util/AssignableArray.h"
#include "Util/JMapLinkInfo.h"

class LiveActor;
class NameObj;

class BaseMatrixFollowValidater
{
public:
	virtual bool isValid(s32) const = 0;
};

class BaseMatrixFollowTarget
{
public:
	BaseMatrixFollowTarget(const JMapLinkInfo *);

	void set(LiveActor *, const TPositionMtx &, const TPositionMtx *, BaseMatrixFollowValidater *);
	MtxPtr getHostBaseMtx() const;

	Mtx mMtx; // _0
	MtxPtr mHostMtx; // _30
	LiveActor* mHost; // _34
	const JMapLinkInfo* mLinkInfo; // _38
	BaseMatrixFollowValidater* mValidater; // _3C
};

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

class BaseMatrixFollowTargetHolder
{
public:
	BaseMatrixFollowTargetHolder(const char *, s32, s32);

	virtual void initAfterPlacement();
	virtual void movement();

	void addFollower(BaseMatrixFollower *);
	void setFollowTargetInfo(LiveActor *, const JMapInfoIter &, const TPositionMtx *, BaseMatrixFollowValidater *);
	BaseMatrixFollowTarget* findFollowTarget(const JMapLinkInfo *);
	BaseMatrixFollowTarget* findFollowTarget(const BaseMatrixFollower *);

	MR::AssignableArray<BaseMatrixFollowTarget*> mTargets; //_14
	s32 mNumTargets; // _1C
	MR::AssignableArray<BaseMatrixFollower*> mFollowers; // _20
	s32 mNumFollowers; // _28
};

namespace MR {
	bool isValidFollowID(const JMapInfoIter &);
	void addBaseMatrixFollower(BaseMatrixFollower *);
	void addBaseMatrixFollowTarget(LiveActor *, const JMapInfoIter &, const TPositionMtx *, BaseMatrixFollowValidater *);
};
