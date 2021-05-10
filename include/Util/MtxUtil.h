#pragma once

#include "JGeometry/TVec3.h"
#include "JGeometry/TPosition3.h"
#include "JGeometry/TMatrix34.h"

#include "kamek.h"

namespace MR
{
    void makeMtxTRS(Mtx, const TVec3f &, const TVec3f &, const TVec3f &);

    void makeMtxUpFront(TPositionMtx *, const TVec3f &, const TVec3f &);

    void makeMtxUpNoSupportPos(TPositionMtx *, const TVec3f &, const TVec3f &);

    void makeMtxFrontUpPos(TPositionMtx *, const TVec3f &, const TVec3f &, const TVec3f &);

    void extractMtxXDir(Mtx, TVec3f *);
    void extractMtxYDir(Mtx, TVec3f *);
    void extractMtxZDir(Mtx, TVec3f *);
    void extractMtxXYZDir(Mtx, TVec3f *, TVec3f *, TVec3f *);
    void extractMtxTrans(Mtx, TVec3f *);

    Mtx* tmpMtxTrans(TVec3f *);
    Mtx* tmpMtxScale(f32, f32, f32);
    Mtx* tmpMtxRotXRad(f32);
    Mtx* tmpMtxRotYRad(f32);
    Mtx* tmpMtxRotZRad(f32);
    Mtx* tmpMtxRotXDeg(f32);
    Mtx* tmpMtxRotYDeg(f32);
    Mtx* tmpMtxRotZDeg(f32);
};
