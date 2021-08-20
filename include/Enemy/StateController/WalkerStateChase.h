#pragma once

#include "Enemy/StateController/WalkerStateParam.h"
#include "LiveActor/LiveActor.h"
#include "LiveActor/State/ActorStateBase.h"

struct WalkerStateChaseParam
{
public:
	f32 mSpeed; // _0
	s32 _4;
	s32 _8;
	f32 mTurnDegrees; // _C
	s32 _10;
};

class WalkerStateChase : public ActorStateBaseInterface
{
public:
	WalkerStateChase(LiveActor *pActor, TVec3f *, WalkerStateParam *pWalkerStateParam, WalkerStateChaseParam *pWalkerStateChaseParam);

	virtual ~WalkerStateChase();
	virtual void appear();

	void exeStart();
	void exeEnd();
	bool isRunning() const;

	LiveActor* mHost; // _C
	WalkerStateParam* mParam; // _10
	WalkerStateChaseParam* mChaseParam; // _14
	TVec3f* _18;
};

namespace NrvWalkerStateChase
{
	NERVE(WalkerStateChaseNrvStart);
	NERVE(WalkerStateChaseNrvEnd);
};
