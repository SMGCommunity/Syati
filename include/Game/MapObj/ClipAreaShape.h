#pragma once

#include "JSystem.h"


class ClipAreaShape {
public:
    ClipAreaShape(const char *pModel);

    virtual bool isInArea(const TVec3f &rPosition) const;
    virtual void calcVolumeMatrix(MtxPtr pVolumeMtx, const TVec3f &, const TVec3f &) const;

    void* mModelData; // _4
};

class ClipAreaShapeSphere : public ClipAreaShape {
public:
    ClipAreaShapeSphere(const char* pName);

    virtual bool isInArea(const TVec3f &rPosition) const;
    virtual void calcVolumeMatrix(MtxPtr pVolumeMtx, const TVec3f &, const TVec3f &) const;

    f32 mRadius; // _C
};

class ClipAreaShapeBox : public ClipAreaShape {
public:
    ClipAreaShapeBox(const char *pModel, s32);

    virtual bool isInArea(const TVec3f &rPosition) const;
    virtual void calcVolumeMatrix(MtxPtr pVolumeMtx, const TVec3f &, const TVec3f &) const;
};

class ClipAreaShapeCylinder : public ClipAreaShape {
public:
    ClipAreaShapeCylinder();

    virtual bool isInArea(const TVec3f &rPosition) const;
    virtual void calcVolumeMatrix(MtxPtr pVolumeMtx, const TVec3f &, const TVec3f &) const;

    f32 mRadius; // _8
    f32 mHeight; // _12
};

class ClipAreaShapeCone : public ClipAreaShape {
public:
    ClipAreaShapeCone(s32);

    virtual bool isInArea(const TVec3f &rPosition) const;
    virtual void calcVolumeMatrix(MtxPtr pVolumeMtx, const TVec3f &, const TVec3f &) const;
};
