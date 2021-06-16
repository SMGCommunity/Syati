#pragma once

#include "Actor/LiveActor/LiveActor.h"

class ActorStateParamScale
{
public:
	ActorStateParamScale(LiveActor * pHost);

	void init(const JMapInfoIter & rIter);
	void init(const ActorStateParamScale * pOther);
	f32 getSpeed();
	f32 getNerveStepRate();
	bool isStep(s32);
	bool isFirstStep();
	bool isGreaterStep(s32 step);
	bool isGreaterEqualStep(s32 step);
	bool isIntervalStep(s32 interval, s32 step);
	// two unknown functions, used by Peto
	void update();
	void resetHostVelocity();
	void calcHostVelocity();
	void calcHostVelocity(const TVec3f & velocity);
	void calcHostVelocity(const TVec3f & velocity, const TVec3f & gravity, f32 speed);
	bool isNeedForReset(const Nerve * nerve, s32 step);

	bool mIsScale; // _0
	bool mUpdateAnim; // _1
	f32 mNerveRate; // _4, 0.0
	f32 mPrevNerveRate; // _8, -1.0
	f32 mParamScale; // _C, 1.0
	f32 mDefaultScale; // _10, 1.0
	TVec3f mResetVelocity; // _14
	Nerve* mNerve; // _20;
	s32 mNerveStep; // _24
	LiveActor* mHost; // _28
	LiveActor* mSwitchHost; // _2C
};
