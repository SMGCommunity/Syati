#pragma once

#include "revolution.h"
#include "JSystem.h"

namespace MR {
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
	void scaleMtxToDir(MtxPtr , const TVec3f &, const TVec3f &);
	void makeMtxTRS(MtxPtr, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	void makeMtxTRS(MtxPtr, const TVec3f &, const TVec3f &, const TVec3f &);
	void setMtxAxisXYZ(MtxPtr, const TVec3f &, const TVec3f &, const TVec3f &);
	void flattenMtx(MtxPtr, MtxPtr, const TVec3f &);
	void flattenMtx(MtxPtr, const TVec3f &);
	void blendMtxRotate(MtxPtr, MtxPtr, f32, MtxPtr);
	void blendMtxRotateSlerp(MtxPtr, MtxPtr, f32, MtxPtr);
	void blendMtx(MtxPtr, MtxPtr, f32, MtxPtr);
	void makeMtxWithoutScale(MtxPtr , const TMtx34f &);
	void makeSRTFromMtxPtr(TVec3f *pTranslate, TVec3f *pEuler, TVec3f *pScale, MtxPtr pMtx, bool);
	void makeRTFromMtxPtr(TVec3f *pTranslate, TVec3f *pEuler, MtxPtr pMtx, bool);
	void makeMtxSideUp(MtxPtr , const TVec3f &, const TVec3f &);
	void makeMtxSideUpPos(MtxPtr , const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxSideFront(MtxPtr , const TVec3f &, const TVec3f &);
	void makeMtxUpSide(MtxPtr , const TVec3f &, const TVec3f &);
	void makeMtxUpSidePos(MtxPtr , const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxUpFront(MtxPtr , const TVec3f &, const TVec3f &);
	void makeMtxUpFrontPos(MtxPtr , const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxFrontSidePos(MtxPtr , const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxFrontUp(MtxPtr , const TVec3f &, const TVec3f &);
	void makeMtxFrontUpPos(MtxPtr , const TVec3f &, const TVec3f &, const TVec3f &);
	void makeMtxUpNoSupport(MtxPtr , const TVec3f &);
	void makeMtxUpNoSupportPos(MtxPtr , const TVec3f &, const TVec3f &);
	void makeMtxFrontNoSupport(MtxPtr , const TVec3f &);
	void makeMtxFrontNoSupportPos(MtxPtr , const TVec3f &, const TVec3f &);
	void orthogonalize(MtxPtr );
	void turnMtxToXDirRate(MtxPtr , const TVec3f &, f32);
	void turnMtxToXDirDegree(MtxPtr , const TVec3f &, f32);
	void turnMtxToYDirRate(MtxPtr , const TVec3f &, f32);
	void turnMtxToYDirDegree(MtxPtr , const TVec3f &, f32);
	void turnMtxToLocalDirDegree(MtxPtr , const TVec3f &, const TVec3f &, f32);
	void makeMtxMoment(MtxPtr , const TVec3f &);

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
	MtxPtr tmpMtxTrans(const TVec3f &);
	MtxPtr tmpMtxScale(f32, f32, f32);
	MtxPtr tmpMtxRotXRad(f32);
	MtxPtr tmpMtxRotYRad(f32);
	MtxPtr tmpMtxRotZRad(f32);
	MtxPtr tmpMtxRotXDeg(f32);
	MtxPtr tmpMtxRotYDeg(f32);
	MtxPtr tmpMtxRotZDeg(f32);
	void orderRotateMtx(s16, const TVec3f &, MtxPtr);
};
