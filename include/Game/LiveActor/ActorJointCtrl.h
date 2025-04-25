#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/LiveActor.h"

class ActorJointCtrl {
public:
	ActorJointCtrl(LiveActor*);

	void startDynamicCtrl(const char*, s32);
	void endDynamicCtrl(const char*, s32);
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
};