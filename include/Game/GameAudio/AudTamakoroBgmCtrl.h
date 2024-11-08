#pragma once

#include "revolution.h"

class JAISoundHandle;

struct TamakoroBgmParamEntry {
    const char* mName;
    u32 _4;
    u32 _8;
    u32 _C;
    f32 _10;
    f32 _14;
    f32 _18;
    f32 _1C;
    f32 _20;
    u32 _24;
    f32 _28;
    u32 _2C;
    u32 _30;
};

class AudTamakoroBgmCtrl {
public:
	AudTamakoroBgmCtrl();

	void init(const char* name);
	void control(f32, bool, s32);
	void modifyTempo(JAISoundHandle*, f32);
	void modifyPitch(JAISoundHandle*, f32);

	s32 _0;
	f32 _4;
	f32 _8;
	f32 _C;
	f32 _10;
	f32 _14;
	s32 _18;
	s32 _1C;
	TamakoroBgmParamEntry* mBgmParam;
	s32 _24;
	s32 _28;
};