#pragma once

#include "kamek.h"
#include "JGeometry/TMatrix34.h"

#ifdef __cplusplus
extern "C" {
#endif

void PSMTXCopy(const Mtx sourceMtx, Mtx destMtx);

f32 PSVECMag(const Vec *);

#ifdef __cplusplus
}
#endif