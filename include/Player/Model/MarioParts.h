#pragma once

#include "LiveActor/PartsModel.h"

class MarioParts : public PartsModel
{
public:
	MarioParts(LiveActor *, const char *, const char *, bool, Mtx4 *, Mtx4 *);
	MarioParts(LiveActor *, const char *, const char *, Mtx4 *);

	virtual ~MarioParts();
	virtual void init(const JMapInfoIter &);

	const char* mEffectGroupName; // _A0
};
