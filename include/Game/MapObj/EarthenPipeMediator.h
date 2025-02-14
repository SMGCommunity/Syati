#pragma once

#include "Game/LiveActor.h"
#include "Game/MapObj/EarthenPipe.h"
#include "revolution.h"

struct EarthenPipeEntry {
    EarthenPipe *_0;
    EarthenPipe *_4;
    s32 mPipeId;        // _8
};

class EarthenPipeMediator : public NameObj {
public:
    EarthenPipeMediator();
    ~EarthenPipeMediator();
    void entry(EarthenPipe *pEarthenPipe, const JMapInfoIter &rIter);

    u32 mNumEntries;            // _14
    EarthenPipeEntry *mEntries; // _18
};