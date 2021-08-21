#pragma once

#include "LiveActor/LiveActor.h"

class ModelObj : public LiveActor
{
public:
    ModelObj(const char *pName, const char *pModelName, MtxPtr pMtx, s32, s32, s32, bool);

    virtual ~ModelObj();
    virtual void init(const JMapInfoIter &);
    virtual void calcAndSetBaseMtx();

    MtxPtr mMtx; // _90
};
