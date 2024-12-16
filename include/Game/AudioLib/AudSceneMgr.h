#pragma once

#include "revolution.h"

class JAUSectionHeap;

struct AudSceneSoundInfo {
public:
	const char* _0; //0x00. Usually the text "Game", though the default is "dummy"
	const char* mStageName; //0x04. The name of the galaxy this entry represents
	const u8 mWaveSystemFileIDs[4]; //0x08. 4 WSYS File IDs (SMR.szs). 0xFF = Load nothing.
};

class AudSceneMgr {
public:
	AudSceneMgr(JAUSectionHeap*);

	void loadStageResource(const char*, const char* pStageName);
	void loadSceneSoundInfo(const AudSceneSoundInfo* pSceneSoundInfo);
	void setSceneAudioEffectType();
	const AudSceneSoundInfo* findSceneSoundInfo(const char*, const char* pStageName);
	void loadWaveSet(const u8* pWaveSystemFileArray, s32 count);


	JAUSectionHeap* mHeap; //0x00
	s32 _4; //0x04
	s32 _8; //0x08
	u8 _C; //0x0C
	u8 _D; //0x0D
};