#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"

class ModelObj : public LiveActor {
public:
    ModelObj(const char *pName, const char *pModelName, MtxPtr pMtx, s32, s32, s32, bool);

    virtual ~ModelObj();
    virtual void init(const JMapInfoIter &rIter);
    virtual void calcAndSetBaseMtx();

    MtxPtr mMtx; // _90
};
