#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/LiveActor.h"

class DynamicJointCtrlKeeper;
class FaceJointCtrlKeeper;
class IKJointCtrlHolder;

class ActorJointCtrl {
public:
	ActorJointCtrl(LiveActor*);

	void startDynamicCtrl(s32); // const char* removed in SMG2
	void endDynamicCtrl(s32); // const char* removed in SMG2
	//Rip resetDynamicCtrl
	void startFaceCtrl(s32);
	void endFaceCtrl(s32);
	void setIKEndPosition(const char*, const TVec3f &, f32);
	void setIKEndDirection(const char*, const TVec3f &, f32);
	void endIKCtrlAll();

	void update();
	void startUpdate();
	void endUpdate();
	void setCallBackFunction();

	LiveActor* mActor;                         // 0x00
	DynamicJointCtrlKeeper* mDynamicJointCtrl; // 0x04
	FaceJointCtrlKeeper* mFaceJointCtrl;       // 0x08
	IKJointCtrlHolder* mIKJointCtrl;           // 0x0C
	bool _10;                                  // 0x10 : CallBack function related
	bool mHasIKJointCtrl;                      // 0x11
};