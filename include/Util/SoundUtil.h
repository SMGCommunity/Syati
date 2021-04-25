#pragma once

#include "kamek.h"

class LiveActor;

namespace MR
{
    void startSound(const LiveActor *, const char *, s32, s32);
	//void startSound(const LiveActor *, JAISoundID, s32, s32); //This is a thing I just have no idea what JAISoundID is
    void startLevelSound(const LiveActor *, const char *, s32, s32, s32);
	void startSoundPlayer(const char *, s32, s32);
};