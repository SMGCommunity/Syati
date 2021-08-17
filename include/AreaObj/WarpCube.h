#pragma once

#include "AreaObj/AreaObj.h"
#include "LiveActor/Camera/ActorCameraInfo.h"

class WarpCube : public AreaObj
{
public:
	inline WarpCube(const char * pName) : AreaObj(pName), mLinkInfo(NULL) {}

	virtual ~WarpCube();
	virtual void init(const JMapInfoIter &);
	virtual void movement();
	virtual void draw();

	JMapIdInfo* mLinkInfo; // _48
	ActorCameraInfo* mCameraInfo; // _4C
	const char* mCameraName; // _50
	u16 mInvalidateTimer; // _54
};

class WarpCubeMgr : public AreaObjMgr
{
public:
	inline WarpCubeMgr(s32, const char * pName) : AreaObj(pName), mEventCameraArea(NULL) {}

	virtual ~WarpCubeMgr();

	AreaObj* getPairCube(const AreaObj *);
	void setInvalidateTimer(AreaObj*, u16);
	void startEventCamera(const AreaObj *);
	void endEventCamera();

	AreaObj* mEventCameraArea; // _24
};
