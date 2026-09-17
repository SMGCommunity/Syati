#pragma once

#include "revolution/types.h"

class LiveActor;

namespace ActorShadow {
    void initShadowFromCSV(LiveActor *pActor, const char *pShadowName, bool defaultVolumeSphere);
};
