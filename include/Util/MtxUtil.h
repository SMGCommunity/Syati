#pragma once

#include "JGeometry/TPosition3.h"
#include "JGeometry/TVec3.h"
#include "kamek.h"

namespace MR
{
	void makeMtxRotate(Mtx4 *, s16, s16, s16);
	void makeMtxRotate(Mtx4 *, f32, f32, f32);
	void makeMtxRotate(Mtx4 *, const TVec3f &);
	void makeMtxRotateY(Mtx4 *, f32);
	void makeMtxTR(Mtx4 *, f32, f32, f32, f32, f32, f32);
	void makeMtxTR(Mtx4 *, const TVec3f &, const TVec3f &);
	void makeMtxTransRotateY(Mtx4 *, f32, f32, f32, f32);
	void rotateMtxLocalX(Mtx4 *, f32);
	void rotateMtxLocalY(Mtx4 *, f32);
	void rotateMtxLocalZ(Mtx4 *, f32);
	void rotateMtxLocalXDegree(Mtx4 *, f32);
	void rotateMtxLocalYDegree(Mtx4 *, f32);
	void rotateMtxLocalZDegree(Mtx4 *, f32);
	void preScaleMtx(Mtx4 *, f32);
	void preScaleMtx(Mtx4 *, const TVec3f &);
	void preScaleMtx(Mtx4 *, f32, f32, f32);
	void scaleMtxToLocalMtx(Mtx4 *, Mtx4 *, Mtx4 *, const TVec3f &);
	void scaleMtxToLocalMtx(Mtx4 *, Mtx4 *, const TVec3f &);
	void scaleMtxToDir(TPositionMtx *, const TVec3f &, const TVec3f &);
	void makeMtxTRS(Mtx4 *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	void makeMtxTRS(Mtx4 *, const TVec3f &, const TVec3f &, const TVec3f &);
	void setMtxAxisXYZ(Mtx4 *, const TVec3f &, const TVec3f &, const TVec3f &);
	void flattenMtx(Mtx4 *, Mtx4 *, const TVec3f &);
	void flattenMtx(Mtx4 *, const TVec3f &);
	void blendMtxRotate(Mtx4 *, Mtx4 *, f32, Mtx4 *);
	void blendMtxRotateSlerp(Mtx4 *, Mtx4 *, f32, Mtx4 *);
	void blendMtx(Mtx4 *, Mtx4 *, f32, Mtx4 *);
	void makeMtxWithoutScale(TPositionMtx *, const TPositionMtx &);

	void makeRTFromMtxPtr(TVec3f *, TVec3f *, Mtx4 *, bool);
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

	void setMtxTrans(Mtx4 *, f32, f32, f32);
	void addTransMtx(Mtx4 *, const TVec3f &);
	void addTransMtxLocal(Mtx4 *, const TVec3f &);
	void addTransMtxLocalX(Mtx4 *, f32);
	void addTransMtxLocalY(Mtx4 *, f32);
	void addTransMtxLocalZ(Mtx4 *, f32);
	void extractMtxXDir(Mtx4 *, TVec3f *);
	void extractMtxYDir(Mtx4 *, TVec3f *);
	void extractMtxZDir(Mtx4 *, TVec3f *);
	void extractMtxXYZDir(Mtx4 *, TVec3f *, TVec3f *, TVec3f *);
	void extractMtxTrans(Mtx4 *, TVec3f *);

	bool isSameMtx(Mtx4 *, Mtx4 *);
	bool isSameMtxRot(Mtx4 *, Mtx4 *);
	bool isRotAxisY(Mtx4 *, Mtx4 *);
	void calcMtxRotAxis(TVec3f *, Mtx4 *, Mtx4 *);
	Mtx* tmpMtxTrans(const TVec3f &);
	Mtx* tmpMtxScale(f32, f32, f32);
	Mtx* tmpMtxRotXRad(f32);
	Mtx* tmpMtxRotYRad(f32);
	Mtx* tmpMtxRotZRad(f32);
	Mtx* tmpMtxRotXDeg(f32);
	Mtx* tmpMtxRotYDeg(f32);
	Mtx* tmpMtxRotZDeg(f32);
	void orderRotateMtx(s16, const TVec3f &, Mtx4 *);
	void rotAxisVecRad(const TVec3f &, const TVec3f &, TVec3f *, f32);
};
