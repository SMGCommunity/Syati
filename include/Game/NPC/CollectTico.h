#pragma once

#include "Game/LiveActor/LiveActor.h"
#include "Game/LiveActor/ActorCameraInfo.h"

class StrayTico;

class CollectTico : public LiveActor {
public:
	CollectTico(const char*);

	virtual ~CollectTico();
	virtual void init(const JMapInfoIter& rIter);

	void exeWait();
	void exeCompleteDemo();
	void exeFlash();
	void exeAppearPowerStar();
	s32 calcNoRescuedCount() const;
	void launch(const TPos3f&);
	void startAppearPowerStar();

	ActorCameraInfo* _90;     // 0x90
	StrayTico** mStrayTicos;  // 0x94
	s32 mTicoNum;             // 0x98
	u8 _A8;                   // 0xA8
	bool mHasCamera;          // 0xA9
	bool mCompleteHere;       // 0xAA : ObjArg0 if set, the silver stars will do the completion animation at the position this object is placed
};

namespace NrvCollectTico {
	NERVE(CollectTicoNrvWait);
	NERVE(CollectTicoNrvTryStartDemo);
	NERVE(CollectTicoNrvCompleteDemo);
	NERVE(CollectTicoNrvFlash);
	NERVE(CollectTicoNrvAppearPowerStar);
}