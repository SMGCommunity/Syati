#pragma once

#include "kamek.h"
#include "NameObj/NameObj.h"
#include "JGeometry/TVec3.h"

class CoinRotater : public NameObj
{
	CoinRotater(const char *);

	virtual ~CoinRotater();
	virtual void movement();

	f32 mRotateY;
	f32 mHiSpeedRotateY;
	f§2 mInWaterRotateY;
	Mtx mMtxRotateY;
	Mtx mMtxHiSpeedRotateY;
	Mtx mMtxInWaterRotateY;
};

namespace MR
{
	CoinRotater* createCoinRotater();
	Mtx* getCoinRotateYMatrix();
	Mtx* getCoinHiSpeedRotateYMatrix();
	Mtx* getCoinInWaterRotateYMatrix();
};
