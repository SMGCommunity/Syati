#pragma once

#include "JMap/JMapInfoIter.h"
#include "Util/Functor.h"

class LiveActor;

namespace MR
{
	bool useStageSwitchReadAppear(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchReadA(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchReadB(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchAwake(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchWriteA(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchWriteB(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchWriteDead(LiveActor *, const JMapInfoIter &);
	bool useStageSwitchWriteAutoDead(LiveActor *, const JMapInfoIter &);

	bool isValidSwitchA(const LiveActor *);
	bool isValidSwitchB(const LiveActor *);
	bool isValidSwitchAppear(const LiveActor *);
	bool isValidSwitchDead(const LiveActor *);
	bool isOnSwitchA(const LiveActor *); //Located at 0x8001A850 USA
	bool isOnSwitchB(const LiveActor *);
	bool isOnSwitchAppear(const LiveActor *);
	bool onSwitchA(LiveActor *);
	bool onSwitchB(LiveActor *);
	bool onSwitchDead(LiveActor *);
	bool offSwitchA(LiveActor *);
	bool offSwitchB(LiveActor *);
	bool offSwitchDead(LiveActor *);
	void syncStageSwitchAppear(LiveActor *);
	bool useStageSwitchSyncAppear(LiveActor *, const JMapInfoIter &); //Located at 0x8001AA10 USA
	void syncStageSwitchAppear(LiveActor *, const JMapInfoIter &); //Located at 0x8001AAB0 USA

	void listenStageSwitchOnA(LiveActor *, const MR::FunctorBase &);
	void listenStageSwitchOnOffA(LiveActor *, const MR::FunctorBase &, const MR::FunctorBase &);
	void listenStageSwitchOnB(LiveActor *, const MR::FunctorBase &);
	void listenStageSwitchOnOffB(LiveActor *, const MR::FunctorBase &, const MR::FunctorBase &);
};
