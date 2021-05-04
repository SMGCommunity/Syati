#pragma once

#include "JGeometry/TVec3.h"
#include "kamek.h"

class LiveActor;
class LayoutActor;

namespace MR
{
	void initStarPointerTarget(LiveActor *, f32, const TVec3f &);
	void initStarPointerTargetAtPos(LiveActor *, f32, const TVec3f *, const TVec3f &);
	void initStarPointerTargetAtJoint(LiveActor *, const char*, f32, const TVec3f &);

	bool isStarPointerValid();

	bool isStarPointerPointing(const LiveActor *, s32, bool, const char *);
	bool tryStarPointerCheckWithoutRumble(LiveActor *, bool);
	bool isStarPointerPointingPane(const LayoutActor *, const char *, s32, bool, const char *);
	bool isStarPointerPointingPaneForMeterLayout(const LayoutActor *, const char *, s32, bool, const char *);
	bool isStarPointerPointingTarget(const LayoutActor *, const char *, s32, bool, const char *);
	bool isStarPointerPointing1P(const LiveActor *, const char *, bool, bool);

	bool isStarPointerPointing2P(const LiveActor *, const char *, bool, bool);
	bool isStarPointerPointing2POnPressButton(const LiveActor *, const char *, bool, bool);
	bool isStarPointerPointing2POnTriggerButton(const LiveActor *, const char *, bool, bool);

	bool isStarPointerPointing1Por2P(const LiveActor *, const char *, bool, bool);
};
