#pragma once

#include "Game/NPC/NPCActor.h"

class GliBirdNpc : public NPCActor {
public:
    GliBirdNpc(const char *pName);
    virtual ~GliBirdNpc();
    virtual void init(const JMapInfoIter &rIter);
};