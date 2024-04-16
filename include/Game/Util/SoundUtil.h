#pragma once

#include "revolution.h"

class LiveActor;

namespace MR {
	bool isDestroySceneKeepAllSound();
	void onDestroySceneKeepAllSound();
	void offDestroySceneKeepAllSound();

	void startSystemSE(const char *, s32, s32);
	void startSystemLevelSE(const char *, s32, s32);
	void stopSystemSE(const char *, u32);

	void startSound(const LiveActor *, const char *, s32, s32);

	void startSound(const LiveActor *, s32 JAISoundID, s32, s32);
	void startLevelSound(const LiveActor *, s32 JAISoundID, s32, s32, s32);
	void startLevelSound(const LiveActor *, const char *, s32, s32, s32);
	void startSoundPlayer(const char *, s32, s32);

	void startSpinHitSound(const LiveActor *);
	void startBlowHitSound(const LiveActor *);
	void startDPDHitSound(); // dummied-out
	void startDPDFreezeLevelSound(const LiveActor *);
	void start2PJumpAssistSound();
	void start2PJumpAssistJustSound();
	void start2PAttackAssistSound();
	void limitedStarPieceHitSound();
	void startStarGetJingle();
	void startGrandStarGetJingle();
};
