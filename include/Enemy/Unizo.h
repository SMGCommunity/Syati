#pragma once

#include "Actor/LiveActor/LiveActor.h"

#define UNIZO 0
#define UNIZO_LAND 1
#define UNIZO_SHOAL 2

class Unizo : public LiveActor
{
public:
	Unizo(const char *);

	s32 mType;
	f32 _94;
	f32 _98;
	f32 _9C;
	f32 _A0;
	Mtx _A4;
	Mtx _D4;
	u32 _104;
	u32 _108;
	u32 _10C;
	u32 _110;
	f32 _114;
	u32 _118;
	u32 _11C;
	u32 _120;
	u32 _124;
	u32 _128;
	f32 _12C;
	f32 _130;
	u32 _134;
};
