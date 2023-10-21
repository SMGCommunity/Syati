#pragma once

#include "JSystem/J3DGraphBase/J3DModel.h"
#include "Game/Animation/XanimeResource.h"

struct XanimeGroupInfo;

class XanimePlayer {
public:
	XanimePlayer(J3DModel*, XanimeResourceTable*);
	XanimePlayer(J3DModel*, XanimeResourceTable*, XanimePlayer*);

	void init();
	bool changeSimpleBck(const char*);
	void changeAnimation(const char*);
	void changeAnimationByHash(u32);
	void swapFrameCtrl(const XanimeGroupInfo*);
	void changeAnimation(const XanimeGroupInfo*);
	void changeCurrentAnimation(const XanimeGroupInfo*);
	void prepareAnimation(const XanimeGroupInfo*);
	void runNextAnimation();
	//void changeAnimationSimple(J3DAnmTransform *);
	void changeSpeed(f32);
	void changeInterpoleFrame(s32);
	bool changeTrackWeight(s32, f32);
	void calcAnm(u16);
	void setModel(J3DModel*);
	void overWriteMtxCalc(u16);
	void clearMtxCalc(u16);
	void clearAnm(u16);
	void updateBeforeMovement();
	void updateAfterMovement();
	void updateInterpoleRatio();
	void getMainAnimationTrans(u32, TVec3f*) const;
	bool isRun(const char*) const;
	// 1 unknown function here
	bool isTerminate(const char*) const;
	bool isTerminate() const;
	void setDefaultAnimation(const char*);
	void runDefaultAnimation();
	bool isAnimationRunSimple() const;
	const char* getCurrentAnimationName() const;
	const char* getDefaultAnimationName() const;
	const char* getCurrentBckName() const;
	const char* getNameStringPointer(const char*) const;
};