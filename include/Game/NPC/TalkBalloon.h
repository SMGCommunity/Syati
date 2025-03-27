#pragma once

#include "revolution.h"
#include "Game/Screen/LayoutActor.h"
#include "Game/NPC/TalkMessageCtrl.h"
#include "Game/NPC/TalkTextFormer.h"
#include "Game/Screen/IconAButton.h"

class TalkBalloon : public LayoutActor {
public:
	TalkBalloon(const char* pName);

	~TalkBalloon();
	virtual void init(const JMapInfoIter& rIter);
	virtual void kill();

	virtual void open(TalkMessageCtrl*);
	virtual void close();
	virtual void updateBalloon();
	virtual void updateTalking();
	virtual void pauseOff();
	virtual bool turnPage();
	virtual bool hasNextPage();
	virtual void skipMessage();
	virtual void isTextAppearedAll();

	void create(const char* pLayoutName, bool hasBeak, bool connectToNormalSceneLayout);

	TalkMessageCtrl* mTalkMsgCtrl; // 0x2C
	TalkTextFormer* mTalkTextFormer; // 0x30
	bool mHasBeak; // 0x34
	bool _35; // 0x35
	u8 _36; // 0x36. Seemingly something relating to sfx?
};

class TalkBalloonShort : public TalkBalloon {
public:
	TalkBalloonShort(const char*);

	~TalkBalloonShort();
	virtual void init(const JMapInfoIter& rIter);

	virtual void open(TalkMessageCtrl*);
	virtual void close();
	virtual void updateBalloon();
};

namespace NrvTalkBalloonShort
{
	// TODO
};

class TalkBalloonEvent : public TalkBalloon {
public:
	TalkBalloonEvent(const char*);

	~TalkBalloonEvent();
	virtual void init(const JMapInfoIter& rIter);

	virtual void open(TalkMessageCtrl*);
	virtual void close();
	virtual bool turnPage();
	virtual void skipMessage();
	virtual void isTextAppearedAll();

	void updateBeak();

	void exeWait();
	void exeOpen();
	void exeTalk();

	s32 _38; // 0x38
	IconAButton _3C; // 0x3C
};

namespace NrvTalkBalloonEvent
{
	// TODO
};

class TalkBalloonSign : public TalkBalloonEvent {
public:
	TalkBalloonSign(const char*);

	~TalkBalloonSign();
	virtual void init(const JMapInfoIter& rIter);
	virtual bool turnPage();
};

class TalkBalloonIcon : public TalkBalloonShort {
public:
	TalkBalloonIcon(const char*);

	~TalkBalloonIcon();
	virtual void init(const JMapInfoIter& rIter);
	virtual void open(TalkMessageCtrl*);
};


class TalkBalloonHolder {
public:
	TalkBalloonHolder();

	TalkBalloon* getBalloon(const TalkMessageCtrl*);
	void pauseOff();
	void update();
	bool isActiveBalloonShort() const;

	TalkBalloonShort (*mTalkBalloonShorts)[4]; // 0x00
	TalkBalloonEvent* mTalkBalloonEvent; // 0x04
	TalkBalloonSign* mTalkBalloonSign; // 0x08
	TalkBalloonIcon* mTalkBalloonIcon; // 0x0C
	s32 _10; // 0x10
	IconAButton* mIconAButton; // 0x14
};