#pragma once

#include "LiveActor/LiveActor.h"

class JetTurtleShadow : public LiveActor
{
public:
	JetTurtleShadow(const char *);

	virtual ~JetTurtleShadow();
	virtual void init(const JMapInfoIter &);

	void calcType0(Mtx4 *);
	void drawType0() const;
};
