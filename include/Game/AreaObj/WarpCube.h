#pragma once

#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

class ActorCameraInfo;
class JMapIdInfo;

class WarpCube : public AreaObj {
public:
	inline WarpCube(const char *pName) : AreaObj(pName), mMapIdInfo() {}

	virtual ~WarpCube();
	virtual void init(const JMapInfoIter &rIter);
	virtual void movement();
	virtual void draw();

    /* 0x48 */ JMapIdInfo* mMapIdInfo;
    /* 0x4C */ ActorCameraInfo* mCameraInfo;
    /* 0x50 */ char* mEventName;
    /* 0x54 */ u16 mInvalidateTimer;
};

class WarpCubeMgr : public AreaObjMgr {
public:
	inline WarpCubeMgr(s32 size, const char *pName) : AreaObjMgr(size, pName), mWarpCube() {}

	virtual ~WarpCubeMgr();

	AreaObj* getPairCube(const AreaObj *pCube);
	void setInvalidateTimer(AreaObj *pCube, u16 timer);
	void startEventCamera(const AreaObj *pCube);
	void endEventCamera();

	/* 0x24 */ const WarpCube* mWarpCube;
};
