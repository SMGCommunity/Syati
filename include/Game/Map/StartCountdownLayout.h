#pragma once

#include "revolution.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/Screen/LayoutActor.h"

class StartCountdownLayout : public LayoutActor
{
public:
	StartCountdownLayout();

	virtual ~StartCountdownLayout();

	virtual void init(const JMapInfoIter& rIter);

	virtual void appear();

	bool isStart() const;

	void exeCountdown();
	void exeStart();
};

namespace NrvStartCountdownLayout
{
	NERVE(HostTypeNrvCountdown);
	NERVE(HostTypeNrvStart);
}