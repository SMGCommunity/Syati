#pragma once

#include "revolution.h"
#include "JSystem.h"

class JMapInfoIter;
class LiveActor;
class TalkMessageCtrl;
class TalkMessageFuncBase;

namespace MR {
    // I (SuperHackio) strongly believe that this class actually has a ton more variables and functions.
    //   All but twp functions got completely inlined in the final game (or maybe they were intentionally inlined)
    //   As an engine dev it just doesn't make much sense to put such a limited amount of things inside here, when there's a lot of other related variables not in here...
    class ActorTalkParam {
    public:
        void setNoTurnAction(const char*);
        void setSingleAction(const char*);

        bool mEnableTurn;            // 0x00 : If false, the NPC will not turn to face the player
        bool mEnableTalkTurn;        // 0x01 : If false, the NPC will not turn to the player when being spoken to
        f32 mTurnDist;               // 0x04 : How close to the NPC you have to be for it to rotate to face the player
        f32 mTurnSpeed;              // 0x08 : How fast the NPC turns to face the player
        f32 _C;                      // 0x0C : turning-related
        f32 _10;                     // 0x10 : turning-related
        const char* mActionWait;     // 0x14 : Animation to use by default just standing around
        const char* mActionWaitTurn; // 0x18 : Animation to use when turning to face the player (or, if the player moves out of range, the animation to use when turning to default)
        const char* mActionTalk;     // 0x1C : Animation to use when talking
        const char* mActionTalkTurn; // 0x20 : Animation to use when turning while talking
    };

    void registerBranchFunc(TalkMessageCtrl *pTalkCtrl, const TalkMessageFuncBase &rTalkFunc);
    void registerEventFunc(TalkMessageCtrl *pTalkCtrl, const TalkMessageFuncBase &rTalkFunc);
    void registerAnimeFunc(TalkMessageCtrl *pTalkCtrl, const TalkMessageFuncBase &rTalkFunc);
    void registerKillFunc(TalkMessageCtrl *pTalkCtrl, const TalkMessageFuncBase &rTalkFunc);
    void setMessageArg(TalkMessageCtrl *pTalkCtrl, int arg);

    TalkMessageCtrl* createTalkCtrl(LiveActor *pActor, const JMapInfoIter &rIter, const TVec3f &rOffset, MtxPtr pFollowMtx);
    TalkMessageCtrl* createTalkCtrlDirect(LiveActor *pActor, const JMapInfoIter &rIter, const char *pLabel, const TVec3f &rOffset, MtxPtr pFollowMtx);
    TalkMessageCtrl* createTalkCtrlDirect(LiveActor *pActor, const char *pLabel, const TVec3f &rOffset, MtxPtr pFollowMtx);
    TalkMessageCtrl* createTalkCtrlDirectOnRootNodeAutomatic(LiveActor *pActor, const JMapInfoIter &rIter, const char *pLabel, const TVec3f &rOffset, MtxPtr pFollowMtx);
    TalkMessageCtrl* tryCreateTalkCtrlDirectOnRootNodeAutomatic(LiveActor *pActor, const JMapInfoIter &rIter, const char *pLabel, const TVec3f &rOffset, MtxPtr pFollowMtx);

    bool tryTalkNearPlayer(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkNearPlayerAtEnd(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkForce(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkForceMarioPuppetable(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkForceAtEnd(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkForceMarioPuppetableAtEnd(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkWithoutDemo(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkWithoutDemoMarioPuppetable(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkWithoutDemoAtEnd(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkWithoutDemoMarioPuppetableAtEnd(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkTimeKeepDemoMarioPuppetable(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkTimeKeepDemoForceWithoutDemo(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkTimeKeepDemoWithoutPauseMarioPuppetable(TalkMessageCtrl *pTalkCtrl);

    bool tryTalkRequest(TalkMessageCtrl *pTalkCtrl);
    bool tryTalkSelectLeft(TalkMessageCtrl *pTalkCtrl);

    const MtxPtr getMessageBallonFollowMtx(const TalkMessageCtrl *pTalkCtrl);
    const TVec3f* getMessageBalloonFollowOffset(const TalkMessageCtrl *pTalkCtrl);
    void setMessageBalloonFollowOffset(TalkMessageCtrl *pTalkCtrl, const TVec3f &rFollowOffset);

    bool isNearPlayer(const TalkMessageCtrl *pTalkCtrl, f32 distance);
    bool isTalkNone(const TalkMessageCtrl *pTalkCtrl);
    bool isTalkEntry(const TalkMessageCtrl *pTalkCtrl);
    bool isTalkTalking(const TalkMessageCtrl *pTalkCtrl);
    bool isTalkEnableEnd(const TalkMessageCtrl *pTalkCtrl);

    void resetNode(TalkMessageCtrl *pTalkCtrl);
    void readMessage(TalkMessageCtrl *pTalkCtrl);
    bool isMessageRead(const TalkMessageCtrl *pTalkCtrl);
    void forwardNode(TalkMessageCtrl *pTalkCtrl);
    void resetAndForwardNode(TalkMessageCtrl *pTalkCtrl, s32 nodeCount);
    bool tryForwardNode(TalkMessageCtrl *pTalkCtrl);
    bool isExistNextNode(const TalkMessageCtrl *pTalkCtrl);

    // one unknown function here...

    bool isShortTalk(const TalkMessageCtrl *pTalkCtrl);
    void setDistanceToTalk(TalkMessageCtrl *pTalkCtrl, f32 distance);
    void onRootNodeAutomatic(TalkMessageCtrl *pTalkCtrl);
    void offRootNodeAutomatic(TalkMessageCtrl *pTalkCtrl);

    // several unknown functions here...

    bool isTalkStart(const TalkMessageCtrl *pTalkCtrl);
};
