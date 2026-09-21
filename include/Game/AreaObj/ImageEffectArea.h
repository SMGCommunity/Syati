#pragma once

#include "Game/AreaObj/AreaObj.h"

/* FINISHED */

#define IMAGE_EFFECT_TYPE_BLOOM   0
#define IMAGE_EFFECT_TYPE_BLUR    1
#define IMAGE_EFFECT_TYPE_DOF     2
#define IMAGE_EFFECT_TYPE_FOG     3
#define IMAGE_EFFECT_TYPE_OUTLINE 4

class ImageEffectArea : public AreaObj {
public:
	ImageEffectArea(int screenType, const char *pName);

	virtual ~ImageEffectArea();
	virtual void init(const JMapInfoIter &rIter);
	virtual bool isSyncWithPlayer() const;

	/* 0x48 */ s32 mEffectType;
};

class ImageEffectAreaMgr : public AreaObjMgr {
public:
	ImageEffectAreaMgr(s32 size, const char *pName);

	virtual ~ImageEffectAreaMgr();
};
