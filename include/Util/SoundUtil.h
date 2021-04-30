#pragma once

#include "kamek.h"

class LiveActor;

namespace MR
{
	void startSystemSE(const char *, s32, s32);

	void startSound(const LiveActor *, const char *, s32, s32);
	void startSound(const LiveActor *, s32 JAISoundID, s32, s32);
	void startLevelSound(const LiveActor *, const char *, s32, s32, s32);
	void startSoundPlayer(const char *, s32, s32);
};
