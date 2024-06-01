#pragma once 

#include "syati.h"
#include "Game/Screen/PauseMenu.h"
#include "Game/Screen/ScenarioTitle.h"
#include "Game/System/PauseButtonCheckerInGame.h"

class GameScene;

class GameSceneScenarioOpeningCameraState : public NerveExecutor {
public:
    GameSceneScenarioOpeningCameraState();
    virtual ~GameSceneScenarioOpeningCameraState();
    void update();
    bool isDone() const;
    void start();
    void end();
    void exePlay();
    bool trySkipTrigger() const;

    TMtx34f _8;
    ScenarioTitle* mScenarioTitle;
};

namespace NrvGameSceneScenarioOpeningCameraState {
    NERVE(GameSceneScenarioOpeningCameraStateNrvWait);
    NERVE(GameSceneScenarioOpeningCameraStateNrvPlay);
}

class GameScenePauseControl : public NerveExecutor {
public:
    GameScenePauseControl(GameScene*);
    virtual ~GameScenePauseControl();
    void registerNervePauseMenu(const Nerve*);
    void requestPauseMenuOff();
    void exeNormal();
    bool tryStartPauseMenu();
    void startPauseMenu();

    GameScene* mGameScene;
    PauseButtonCheckerInGame* mPauseButtonCheckerInGame; // 0xC
    bool mMode; // 0x10
    Nerve* mPauseMenuNerve; // 0x14
};

namespace NrvGameScenePauseControl {
    NERVE(GameScenePauseControlNrvNormal);
};

class GamePauseSequence : public LayoutActor {
public:
    enum MenuType {
        MENU_TYPE_0,
        MENU_TYPE_1
    };
    
    GamePauseSequence();
    virtual ~GamePauseSequence();
    void init(const JMapInfoIter&);
    void initWindowMenu(const MR::FunctorBase&);
    void startPause(MenuType);
    void deactivate();
    void exeActivePauseMenu();

    MenuType mMenuType;
    PauseMenu* mPauseMenu;
    MR::FunctorBase* mFunc;
};

namespace NrvGamePauseSequence {
    NERVE(GamePauseSequenceNrvSceneInformation);
    NERVE(GamePauseSequenceNrvActivePauseMenu);
    NERVE(GamePauseSequenceNrvDeactive);
};

class GameStageClearSequence : public LayoutActor {
public: 
    GameStageClearSequence();
    virtual ~GameStageClearSequence();
    virtual void init(const JMapInfoIter&);
    void startPowerStarGetDemo();
    void startGrandStarGetDemo();
    void appearGetStarLayout();
    void exePowerStarGetDemo();
    void exeGrandStarGetDemo();

    SimpleEffectLayout* mGetStarLayout;
    TVec2f mLayoutFollowPos;
};

namespace NrvGameStageClearSequence {
    NERVE(GameStageClearSequencePowerStarGetDemo);
    NERVE(GameStageClearSequenceGrandStarGetDemo);
};
