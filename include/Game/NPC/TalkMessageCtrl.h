#pragma once

#include "revolution.h"
#include "Game/NPC/TalkMessageFunc.h"
#include "Game/NPC/TalkMessageInfo.h"
#include "Game/NameObj.h"
#include "Game/LiveActor.h"

class TalkNodeCtrl;

struct CustomTagArg {
    union {
        int mNumberArg;
        const wchar_t* mStringArg;
    };
    s32 mType;
};

class TalkMessageCtrl : public NameObj {
public:
    TalkMessageCtrl(LiveActor* actor, const TVec3f&, MtxPtr*);
    virtual ~TalkMessageCtrl();

    void createMessage(const JMapInfoIter&, const char*);
    void createMessageDirect(const JMapInfoIter&, const char*);
    s32 getMessageID() const;
    void requestTalk();
    void requestTalkForce();
    void startTalk();
    void startTalkForce();
    void startTalkForcePuppetable();
    void startTalkForceWithoutDemo();
    void startTalkForceWithoutDemoPuppetable();
    void endTalk();
    void updateBalloonPos();
    bool isNearPlayer(const TalkMessageCtrl*);
    bool isNearPlayer(f32);
    void startCamera(s32);
    void rootNodePre(bool);
    void rootNodePst();
    bool isCurrentNodeContinue() const;
    void rootNodeEve();
    void rootNodeSel(bool);
    void setMessageArg(const CustomTagArg&);
    void registerBranchFunc(const TalkMessageFuncBase&);
    void registerEventFunc(const TalkMessageFuncBase&);
    void registerAnimeFunc(const TalkMessageFuncBase&);
    void registerKillFunc(const TalkMessageFuncBase&);
    void readMessage();
    bool isSelectYesNo() const;
    const char* getBranchID() const;
    bool isExistNextNode() const;

    LiveActor* mHost; // 0x14
    TalkNodeCtrl* mTalkNodeCtrl; // 0x18
    s32 _1C;
    s32 _20;
    s32 _24;
    s32 _28;
    s32 _2C;
    MtxPtr _30;
    TVec3f _34;
    f32 _40;
    bool mAlreadyDoneFlag; // 0x44
    s32 _48; // Used at 0x8037B584,
    bool _4C;
    bool _4D;
    bool _4E;
    bool _4F;
    bool mShowFrame; // 0x50
    bool _51;
    bool _52;
    bool _53;
    bool _54;
    ActorCameraInfo* mActorCameraInfo; // 0x58
    TalkMessageFuncBase* mBranchFunc; // 0x5C
    TalkMessageFuncBase* mEventFunc; // 0x60
    TalkMessageFuncBase* mAnimeFunc; // 0x64
    TalkMessageFuncBase* mKillFunc; // 0x68
    CustomTagArg mCustomTagArg;
};    

namespace TalkFunction {
    bool isShortTalk(const TalkMessageCtrl*);
    bool isGlobalEventTalk(const TalkMessageCtrl*);
    bool isSelectTalk(const TalkMessageCtrl*);
    bool isEventNode(const TalkMessageCtrl*);
    bool isForwardNode(const TalkMessageCtrl*);
    void onTalkStateNone(TalkMessageCtrl*);
    void onTalkStateEntry(TalkMessageCtrl*);
    void onTalkStateEnableStart(TalkMessageCtrl*);
    void onTalkStateTalking(TalkMessageCtrl*);
    void onTalkStateEnableEnd(TalkMessageCtrl*);
    TalkMessageInfo* getMessageInfo(const TalkMessageCtrl*);
    const wchar_t* getMessage(const TalkMessageCtrl*);
}

// This does not go here
class MessageEditorMessageTag {
    public:
    u32* _0;

    u8 getParam8(int) const;
    u16 getParam16(int) const;
};
