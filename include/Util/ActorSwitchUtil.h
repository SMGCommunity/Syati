#pragma once

#include "JMap/JMapInfoIter.h"

class LiveActor;

namespace MR
{
    bool useStageSwitchReadA(LiveActor *, const JMapInfoIter &);
    bool useStageSwitchReadB(LiveActor *, const JMapInfoIter &);
    bool useStageSwitchReadAppear(LiveActor *, const JMapInfoIter &);
    bool useStageSwitchWriteA(LiveActor *, const JMapInfoIter &);
    bool useStageSwitchWriteB(LiveActor *, const JMapInfoIter &);
    bool useStageSwitchAwake(LiveActor *, const JMapInfoIter &);

    bool useStageSwitchReadDead(LiveActor *, const JMapInfoIter &);

    void syncStageSwitchAppear(LiveActor *);

	bool isValidSwitchA(const LiveActor *);
	bool isValidSwitchB(const LiveActor *);
	bool isValidSwitchAppear(const LiveActor *);
	bool isValidSwitchDead(const LiveActor *);
};