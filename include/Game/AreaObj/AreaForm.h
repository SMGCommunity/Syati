#pragma once

#include "JSystem/JGeometry.h"

class JMapInfoIter;

enum AreaFormType {
	AreaForm_Cube,
	AreaForm_CenteredCube,
	AreaForm_Sphere,
	AreaForm_Cylinder,
	AreaForm_Bowl
};

class AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter) = 0;
	virtual bool isInVolume(const TVec3f &rPosition) const = 0;

	MtxPtr mFollowMtx; // _4 TODO: Is this correct?
};

class AreaFormCube : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rPosition) const;

	void calcWorldPos(TVec3f *pPosition) const;
	void calcWorldRotate(TVec3f *pRotation) const;
	void calcWorldBox(TDirBox3f *pWorldBox) const;
	void calcLocalPos(TVec3f *pPosition, const TVec3f &rPosition) const;
	void calcLocalRotate(TVec3f *pRotation, const TVec3f &rRotation) const;

	f32 getBaseSize();
	void updateBoxParam();
	void calcWorldMtx(MtxPtr pWorldMtx) const;

	/* 0x08 */ int mCentered;
	/* 0x0C */ TVec3f mTranslation;
	/* 0x18 */ TVec3f mRotation;
	/* 0x24 */ TVec3f mScale;
	/* 0x30 */ TBox3f mLocalBox;
	/* 0x48 */ TPos3f mWorldMtx;
};

class AreaFormSphere : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rPosition) const;

	void calcUpVec(TVec3f *pUpVec) const;
	void calcFrontUpVec(TVec3f *pFrontVec) const;
	void calcPos(TVec3f *pPosition) const;
	
	/* 0x08 */ TVec3f mTranslation;
	/* 0x14 */ f32 mRadius;
	/* 0x18 */ TVec3f mUpVec;
	/* 0x24 */ TVec3f mFrontVec;
};

class AreaFormBowl : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rPosition) const;

	void calcUpVec(const TVec3f &rEulerRot);
	
	/* 0x08 */ TVec3f mTranslation;
	/* 0x14 */ TVec3f mUpVec;
	/* 0x20 */ f32 mRadius;
};

class AreaFormCylinder : public AreaForm {
public:
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isInVolume(const TVec3f &rPosition) const;
	
	void calcPos(TVec3f *pPosition) const;
	void calcCenterPos(TVec3f *pCenterPos) const;
	void calcUpVec(TVec3f *pUpVec) const;
	void calcDir(TVec3f &rEulerRot);
	
	/* 0x08 */ TVec3f mTranslation;
	/* 0x14 */ TVec3f mUpVec;
	/* 0x20 */ f32 mRadius;
	/* 0x24 */ f32 mHeight;
};

namespace MR {
	AreaForm* createAreaForm(int shapeNo);
}
