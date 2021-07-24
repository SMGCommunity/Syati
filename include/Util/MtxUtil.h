#pragma once

#include "JGeometry/TPosition3.h"
#include "JGeometry/TVec3.h"
#include "syati.h"

namespace MR
{
	void makeMtxRotate(MtxPtr, s16, s16, s16);
	void makeMtxRotate(MtxPtr, f32, f32, f32);
	void makeMtxRotate(MtxPtr, const TVec3f &);
	void makeMtxRotateY(MtxPtr, f32);
	void makeMtxTR(MtxPtr, f32, f32, f32, f32, f32, f32);
	void makeMtxTR(MtxPtr, const TVec3f &, const TVec3f &);
	void makeMtxTransRotateY(MtxPtr, f32, f32, f32, f32);
	void rotateMtxLocalX(MtxPtr, f32);
	void rotateMtxLocalY(MtxPtr, f32);
	void rotateMtxLocalZ(MtxPtr, f32);
	void rotateMtxLocalXDegree(MtxPtr, f32);
	void rotateMtxLocalYDegree(MtxPtr, f32);
	void rotateMtxLocalZDegree(MtxPtr, f32);
	void preScaleMtx(MtxPtr, f32);
	void preScaleMtx(MtxPtr, const TVec3f &);
	void preScaleMtx(MtxPtr, f32, f32, f32);
	void scaleMtxToLocalMtx(MtxPtr, MtxPtr, MtxPtr, const TVec3f &);
	void scaleMtxToLocalMtx(MtxPtr, MtxPtr, const TVec3f &);
	void scaleMtxToDir(TPositionMtx *, const TVec3f &, const TVec3f &);
	void makeMtxTRS(MtxPtr, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	void makeMtxTRS(MtxPtr, const TVec3f &, const TVec3f &, const TVec3f &);
	void setMtxAxisXYZ(MtxPtr, const TVec3f &, const TVec3f &, const TVec3f &);
	void flattenMtx(MtxPtr, MtxPtr, const TVec3f &);
	void flattenMtx(MtxPtr, const TVec3f &);
	void blendMtxRotate(MtxPtr, MtxPtr, f32, MtxPtr);
	void blendMtxRotateSlerp(MtxPtr, MtxPtr, f32, MtxPtr);
	void blendMtx(MtxPtr, MtxPtr, f32, MtxPtr);
	void makeMtxWithoutScale(TPositionMtx *, const TPositionMtx &);

	void makeRTFromMtxPtr(TVec3f *, TVec3f *, MtxPtr, bool);
	void makeMtxSideUp(TPositionMtx *, const TVec3f &, const TVec3f &);
	void makeMtxSideUpPos(TPositionMtx *, const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxSideFront(TPositionMtx *, const TVec3f &, const TVec3f &);
	void makeMtxUpSide(TPositionMtx *, const TVec3f &, const TVec3f &);
	void makeMtxUpSidePos(TPositionMtx *, const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxUpFront(TPositionMtx *, const TVec3f &, const TVec3f &);
	void makeMtxUpFrontPos(TPositionMtx *, const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxFrontSidePos(TPositionMtx *, const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxFrontUp(TPositionMtx *, const TVec3f &, const TVec3f &);
	void makeMtxFrontUpPos(TPositionMtx *, const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxUpNoSupport(TPositionMtx *, const TVec3f &);
	void makeMtxUpNoSupportPos(TPositionMtx *, const TVec3f &, const TVec3f &);
	void makeMtxFrontNoSupport(TPositionMtx *, const TVec3f &);
	void makeMtxFrontNoSupportPos(TPositionMtx *, const TVec3f &, const TVec3f &);
	void orthogonalize(TPositionMtx *);
	void turnMtxToXDirRate(TPositionMtx *, const TVec3f &, f32);
	void turnMtxToXDirDegree(TPositionMtx *, const TVec3f &, f32);
	void turnMtxToYDirRate(TPositionMtx *, const TVec3f &, f32);
	void turnMtxToYDirDegree(TPositionMtx *, const TVec3f &, f32);
	void turnMtxToLocalDirDegree(TPositionMtx *, const TVec3f &, const TVec3f &, f32);
	void makeMtxMoment(TPositionMtx *, const TVec3f &);

	void setMtxTrans(MtxPtr, const TVec3f &);
	void setMtxTrans(MtxPtr, f32, f32, f32);
	void addTransMtx(MtxPtr, const TVec3f &);
	void addTransMtxLocal(MtxPtr, const TVec3f &);
	void addTransMtxLocalX(MtxPtr, f32);
	void addTransMtxLocalY(MtxPtr, f32);
	void addTransMtxLocalZ(MtxPtr, f32);
	void extractMtxXDir(MtxPtr, TVec3f *);
	void extractMtxYDir(MtxPtr, TVec3f *);
	void extractMtxZDir(MtxPtr, TVec3f *);
	void extractMtxXYZDir(MtxPtr, TVec3f *, TVec3f *, TVec3f *);
	void extractMtxTrans(MtxPtr, TVec3f *);

	bool isSameMtx(MtxPtr, MtxPtr);
	bool isSameMtxRot(MtxPtr, MtxPtr);
	bool isRotAxisY(MtxPtr, MtxPtr);
	void calcMtxRotAxis(TVec3f *, MtxPtr, MtxPtr);
	Mtx* tmpMtxTrans(const TVec3f &);
	Mtx* tmpMtxScale(f32, f32, f32);
	Mtx* tmpMtxRotXRad(f32);
	Mtx* tmpMtxRotYRad(f32);
	Mtx* tmpMtxRotZRad(f32);
	Mtx* tmpMtxRotXDeg(f32);
	Mtx* tmpMtxRotYDeg(f32);
	Mtx* tmpMtxRotZDeg(f32);
	void orderRotateMtx(s16, const TVec3f &, MtxPtr);
	void rotAxisVecRad(const TVec3f &, const TVec3f &, TVec3f *, f32);
};
