#pragma once

#include "revolution/types.h"
#include "revolution/gx/GXStruct.h"
#include "Game/NameObj/NameObjHolder.h"
#include "Game/Screen/StarPointerDirector.h"
#include "Game/System/WPadHolder.h"
#include "JSystem/JMath.h"

class ParticleResourceHolder;
class CaptureScreenDirector;
class ScreenPreserver;
class AudSystemWrapper;
class FunctionAsyncExecutor;
class MessageHolder;

class GameSystemObjHolder {
public:
    GameSystemObjHolder();
    
    void initAfterStationedResourceLoaded();
    void initMessageResource();
    void init();
    void createAudioSystem();
    void update();
    void updateAudioSystem();
    void clearRequestFileInfo(bool);
    void drawStarPointer();
    void drawBeforeEndRender();
    void captureIfAllowForScreenPreserver();
    GXRenderModeObj* getRenderModeObj() const;
    void initDvd();
    void initNAND();
    void initAudio();
    void initRenderMode();
    void initNameObj();
    void initResourceHolderManager();
    void initGameController();
    void initDisplay();

    NameObjHolder *mNameObjHolder;              // _0
    ParticleResourceHolder* mParticleResHolder; // _4
    GXRenderModeObj* mRenderModeObj;            // _8
    void *_C;
    void *_10;
    void *_14;
    CaptureScreenDirector* mCaptureScreenDir;   // _18
    ScreenPreserver* mScreenPreserver;          // _1C
    AudSystemWrapper* mSysWrapper;              // _20
    WPadHolder* mWPadHolder;                    // _24
    FunctionAsyncExecutor* mAsyncExec;          // _28
    MessageHolder* mMsgHolder;                  // _2C
    StarPointerDirector* mStarPointerDir;       // _30
    JMath::TRandom_fast_ mRandom;               // _34
    u32 mLanguage;                              // _38
    u32 _3C;
    u32 _40;
};