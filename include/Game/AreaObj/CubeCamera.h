#pragma once

#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class CubeCameraArea : public AreaObj {
public:
	CubeCameraArea(const char *pName);

	virtual ~CubeCameraArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual bool isInVolume(const TVec3f &rPosition) const;
	virtual s32 getAreaPriority() const;
	virtual const char* getManagerName() const;
	virtual s32 getCategoryArg() const;

	bool isValidCameraID() const;
	u16 getCameraID() const;
	void setCurrentCategory(s32 category);

	/* 0x48 */ u16 mCameraId;
	/* 0x4C */ s32 mZoneId;
};

class CubeCameraMgr : public AreaObjMgr {
public:
	CubeCameraMgr(s32 size, const char *pName);

	virtual ~CubeCameraMgr();

	void initAfterLoad();
};
