#pragma once

#include "JMap/JMapInfoIter.h"

class LiveActor;

namespace MR
{
    void useStageSwitchReadAppear(LiveActor *, const JMapInfoIter &);
    void needStageSwitchReadAppear(LiveActor *, const JMapInfoIter &);

    void useStageSwitchWriteDead(LiveActor *, const JMapInfoIter &);
    void needStageSwitchWriteDead(LiveActor *, const JMapInfoIter &);

    void useStageSwitchReadA(LiveActor *, const JMapInfoIter &);
    void useStageSwitchWriteA(LiveActor *, const JMapInfoIter &);
    void needStageSwitchReadA(LiveActor *, const JMapInfoIter &);
    void needStageSwitchWriteA(LiveActor *, const JMapInfoIter &);

    void onSwitchA(LiveActor *);
    void onSwitchB(LiveActor *);
    void onSwitchDead(LiveActor *);

    void offSwitchA(LiveActor *);
    void offSwitchB(LiveActor *);
};