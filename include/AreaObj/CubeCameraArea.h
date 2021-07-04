#pragma once

#include "AreaObj/AreaObj.h"

class CubeCameraArea : public AreaObj
{
public:
	CubeCameraArea(const char *);

	virtual ~CubeCameraArea();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
	virtual bool isInVolume(const TVec3f &) const;
	virtual s32 getAreaPriority() const;
	virtual const char* getManagerName() const;
	virtual s32 getCategoryArg() const;

	bool isValidCameeraID() const;
	u16 getCameraID() const;
	void setCurrentCategory(s32);

	u16 mCameraId;
	s32 mZoneId;
};

class CubeCameraMgr : public AreaObjMgr
{
public:
	CubeCameraMgr(const char *);

	virtual ~CubeCameraMgr();

	void initAfterLoad();
};
