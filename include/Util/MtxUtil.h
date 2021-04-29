#pragma once

#include "JGeometry/TVec3.h"
#include "JGeometry/TPosition3.h"
#include "JGeometry/TMatrix34.h"

#include "kamek.h"

namespace MR
{
    void makeMtxTRS(Mtx, const JGeometry::TVec3<f32> &, const JGeometry::TVec3<f32> &, const JGeometry::TVec3<f32> &);

    void makeMtxFrontUpPos(TPositionMtx *, const JGeometry::TVec3<f32> &, const JGeometry::TVec3<f32> &, const JGeometry::TVec3<f32> &);

    void extractMtxXDir(Mtx, JGeometry::TVec3<f32> *);
    void extractMtxYDir(Mtx, JGeometry::TVec3<f32> *);
    void extractMtxZDir(Mtx, JGeometry::TVec3<f32> *);
    void extractMtxXYZDir(Mtx, JGeometry::TVec3<f32> *, JGeometry::TVec3<f32> *, JGeometry::TVec3<f32> *);
    void extractMtxTrans(Mtx, JGeometry::TVec3<f32> *);

    Mtx* tmpMtxTrans(JGeometry::TVec3<f32> *);
    Mtx* tmpMtxScale(f32, f32, f32);
    Mtx* tmpMtxRotXRad(f32);
    Mtx* tmpMtxRotYRad(f32);
    Mtx* tmpMtxRotZRad(f32);
    Mtx* tmpMtxRotXDeg(f32);
    Mtx* tmpMtxRotYDeg(f32);
    Mtx* tmpMtxRotZDeg(f32);
};
