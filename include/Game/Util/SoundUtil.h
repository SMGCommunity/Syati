#pragma once

#include "revolution.h"
#include "Game/GameAudio/AudTalkSoundData.h"

class LiveActor;


namespace MR {
	bool isDestroySceneKeepAllSound();
	void onDestroySceneKeepAllSound();
	void offDestroySceneKeepAllSound();

	void startSystemSE(const char *, s32, s32);
	void startSystemSE(JAISoundID, s32, s32);
	void startSystemLevelSE(const char *, s32, s32);
	void stopSystemSE(JAISoundID, u32);
	void stopSystemSE(const char *, u32);

	void startSound(const LiveActor *, const char *, s32, s32);

	void startSound(const LiveActor *, s32 JAISoundID, s32, s32);
	void startLevelSound(const LiveActor *, s32 JAISoundID, s32, s32, s32);
	void startLevelSound(const LiveActor *, const char *, s32, s32, s32);
	void stopSound(const LiveActor*, const char*, u32);
	void stopSound(const LiveActor*, JAISoundID, u32);
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

	void startAtmosphereSE(const char*, s32, s32);
	void startAtmosphereLevelSE(const char*, s32, s32);

	// not positioned in order
	void startSoundObject(AudSoundObject*, const char*);
	void startSoundObjectLevel(AudSoundObject*, const char*, s32);
};
