#pragma once

#include "Util/Functor.h"
#include "kamek.h"

class LiveActor;
class NameObj;

class NameObjListExecutor
{
public:
	NameObjListExecutor();

	virtual ~NameObjListExecutor();
	virtual void initMovementList();
	virtual void initCalcAnimList();
	virtual void initCalcViewAndEntryList();
	virtual void initDrawList();

	void init();
	void registerDrawBuffer(LiveActor *, int);
	void allocateDrawBufferActorList();
	void registerPreDrawFunction(const MR::FunctorBase &, int);

	void findLightInfo(LiveActor *, int, int) const;
	void incrementCheckMovement(NameObj *, int);
	void incrementCheckCalcAnim(NameObj *, int);
	void incrementCheckDraw(NameObj *, int);
	void addToMovement(NameObj *, int);
	void addToCalcAnim(NameObj *, int);
	void addToDrawBuffer(LiveActor *, int, int);
	void addToDraw(NameObj *, int);
	void removeToMovement(NameObj *, int);
	void removeToCalcAnim(NameObj *, int);
	void removeToDrawBuffer(LiveActor *, int, int);
	void removeToDraw(NameObj *, int);
	void executeMovement(int);
	void executeCalcAnim(int);
	void entryDrawBuffer2D();
	void entryDrawBuffer3D();
	void entryDrawBufferMirror();

	void drawOpa(int);
	void drawXlu(int);
	void executeDraw(int);
	void initMovementList();
	void initCalcAnimList();
	void initCalcViewAndEntryList();
	void initDrawList();

	u32* mDrawBuffer; // _4; MR::Vector<AssignableArray<DrawBufferGroup>>
	u32* mMovementList; // _8
	u32* mCalcAnimList; // _C
	u32* mDrawList; // _10
};
