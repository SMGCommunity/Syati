#pragma once

#include "NameObj/NameObj.h"
#include "Util/Functor.h"

class NameObjAdaptor : public NameObj
{
public:
	NameObjAdaptor(const char *);

	virtual ~NameObjAdaptor();
	virtual void movement();
	virtual void draw();
	virtual void calcAnim();
	virtual void calcViewAndEntry();

	void connectToMovement(const MR::FunctorBase &);
	void connectToCalcAnim(const MR::FunctorBase &);
	void connectToDraw(const MR::FunctorBase &);
	
	MR::FunctorBase* mMovementFunctor; // _14
	MR::FunctorBase* mCalcAnimFunctor; // _18
	MR::FunctorBase* mCalcViewAndEntryFunctor; // _1C
	MR::FunctorBase* mDrawFunctor; // _20
};
