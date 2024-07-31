#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"
#include "Game/NPC/TalkMessageCtrl.h"

class TalkTextFormer {
public:
	TalkTextFormer(LayoutActor*, const char*);

	void formMessage(const wchar_t* pMsg, s32);
	void setArg(const CustomTagArg&, s32);
	bool nextPage();
	bool hasNextPage() const;
	void updateTalking();
	bool isTextAppearedAll() const;

	LayoutActor* mHostActor;    // _0
	const wchar_t* mMsg;        // _4
	u32 _8;
	const char* mPaneName;      // _C
};

// Needs to be added somehow...
//getTextBoxPane(LayoutActor*, const char*);