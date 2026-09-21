#pragma once

#include "Game/AreaObj/ImageEffectArea.h"

/* FINISHED */

class BloomArea : public ImageEffectArea {
public:
	BloomArea(const char *pName);

	virtual ~BloomArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual const char* getManagerName() const;

    /* 0x4C */ u8 mThreshold;
    /* 0x4D */ u8 mIntensity;
    /* 0x50 */ s32 mIntensity1;
    /* 0x54 */ s32 mIntensity2;
};
