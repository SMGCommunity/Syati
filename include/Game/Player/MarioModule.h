#pragma once

#include "revolution.h"
#include "JSystem.h"

class MarioActor;
class Mario;

class MarioModule {
public:
	virtual f32 getStickY() const;
	virtual void addVelocity(const TVec3f&);
	virtual void addVelocity(const TVec3f&, f32);

    void changeAnimation(const char *, const char *);
    void playSound(const char *, s32);
	bool isAnimationRun(const char*) const;

	bool isPlayerModeYoshi() const;
	Mario* getPlayer() const;

	MarioActor* mMarioActor; // _4
};
