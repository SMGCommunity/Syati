#pragma once

#include "JSystem.h"

class ProjmapEffectMtxSetter {
public:
    void updateMtxUseBaseMtx();
    void updateMtxUseBaseMtxWithLocalOffset(const TVec3f&);
};