#pragma once

#include "NameObj/NameObj.h"

class LayoutActorFlag {
public:
	bool mIsDead;
	bool mIsStopAnimFrame;
	bool mIsHidden;
	bool mIsOnCalcAnim;
};

class LayoutActor : public NameObj {
public:
	LayoutActor(const char *, bool);

	virtual ~LayoutActor();
	virtual void movement();
	virtual void draw() const;
	virtual void calcAnim();
	virtual void appear();
	virtual void kill();
	virtual void control();

	void initLayoutManager(const char *, u32);

	s32 _14;
	s32 _18;
	s32 _1C;
	s32 _20;
	LayoutActorFlag mLayoutActorFlag; // _28
	s32 _28;
};
