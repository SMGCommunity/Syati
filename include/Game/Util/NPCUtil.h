#pragma once

#include "revolution.h"
#include "Game/System/NerveExecutor.h"
#include "Game/LiveActor/Spine.h"

class NPCActorItem;
class NPCActor;

namespace MR {
	void getNPCItemData(NPCActorItem*, s32);
	bool tryTalkNearPlayerAndStartTalkAction(NPCActor*);
	bool tryTalkNearPlayerAtEndAndStartTalkAction(NPCActor*);
	bool isActionContinuous(const LiveActor*);
	void decidePose(NPCActor*, const TVec3f&, const TVec3f&, const TVec3f&, f32, f32, f32);
	void tryStartMoveTurnAction(NPCActor*);
	void tryStartTurnAction(NPCActor*);
	void followRailPose(NPCActor*, f32, f32);
	void setDefaultPose(NPCActor*);
	void tryStartReactionAndPopNerve(NPCActor*);
};

class TakeOutStar : public NerveExecutor {
public:
	TakeOutStar(NPCActor*, const char*, const char*, const Nerve*, s32);

	bool takeOut();
	bool isFirstStep();
	bool isLastStep();

	void exeAnim();
	void exeDemo();

	ModelObj* _8;
	NPCActor* pHost;
	u32 _10;
	u32 _14;
	u32 _18;
	u32 _1C;
};

namespace NrvTakeOutStar {
	NERVE(TakeOutStarNrvAnim);
	NERVE(TakeOutStarNrvDemo);
	NERVE(TakeOutStarNrvTerm);
}