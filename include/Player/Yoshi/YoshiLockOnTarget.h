#pragma once

#include "LiveActor/LiveActor.h"

class YoshiLockOnTarget
{
public:
	YoshiLockOnTarget(LiveActor *, Mtx4*, const TVec3f &);

	LiveActor* mHost; // _0
	Mtx4* mFollowMtx; // _4
	TVec3f mOffset; // _8
	bool _14;
};

namespace MR
{
	YoshiLockOnTarget* createYoshiLockOnTarget(LiveActor *, Mtx4 *, const TVec3f &);
	YoshiLockOnTarget* createYoshiLockOnTarget(LiveActor *, const char *, const TVec3f &);
};
