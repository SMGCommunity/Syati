#pragma once

#include "Actor/LiveActor/LiveActor.h"

namespace MR
{
	bool tryRegisterDemoCast(LiveActor *, const JMapInfoIter &);

	void registerDemoActionNerve(const LiveActor *, const Nerve *, const char *);

	bool isDemoCast(const LiveActor *, const char *);
};
