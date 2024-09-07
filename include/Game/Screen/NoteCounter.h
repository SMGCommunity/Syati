#pragma once

#include "Game/Screen/LayoutActor.h"

class LiveActor;

class NoteCounter : public LayoutActor {
public:
	NoteCounter(const char*);

	virtual ~NoteCounter();
	virtual void init(const JMapInfoIter& rIter);

	void declareNoteNumMaxAndMelody(LiveActor*, s32 NoteNum, s32, f32);
	void add();
	void tryEndDisp();

	void exeShowToHide();
	void exeHideToShow();

	s32 mNoteNumMax; //_2C
	s32 mNoteNum; //_30
	s32 _34; //_34
	s32 mMelody; //_38
	f32 _3C; //_3C
	LiveActor* _40;
};

namespace NrvNoteCounter {
	NERVE(NoteCounterNrvShow);
	NERVE(NoteCounterNrvShowWait);
	NERVE(NoteCounterNrvShowToHide);
	NERVE(NoteCounterNrvHideToShow);
	NERVE(NoteCounterNrvHide);
}