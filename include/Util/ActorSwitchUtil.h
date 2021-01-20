#pragma once

#include "JMap/JMapInfoIter.h"

class LiveActor;

namespace MR
{
    bool useStageSwitchReadAppear(LiveActor *, const JMapInfoIter &iter);

    void syncStageSwitchAppear(LiveActor *);
};