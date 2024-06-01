#pragma once

#include "syati.h"
#include "Game/Scene/GameSceneSequences.h"

class GameScene : public Scene {
public:
    GameScene();
    virtual ~GameScene();
    virtual void init();
    virtual void start();
    virtual void update();
    virtual void draw() const;
    virtual void calcAnim();
    void notifyEndScenarioStarter();
    void requestStartGameOverDemo();
    void requestEndGameOverDemo();
    void requestPowerStarGetDemo();
    void requestGrandStarGetDemo();
    void setNerveAfterPauseMenu();
    bool isExecScenarioOpeningCamera() const;
    bool isExecScenarioStarter() const;
    bool isExecStageClearDemo() const;
    void initSequences();
    void initEffect();
    void draw3D() const;
    bool isDrawMirror() const;
    void stageClear();

    s32 _14;
    GameSceneScenarioOpeningCameraState* mGameSceneScenarioOpeningCameraState; // 0x18
    GameScenePauseControl* mGameScenePauseControl; // 0x1C
    GamePauseSequence* mGamePauseSequence; // 0x20
    GameStageClearSequence* mGameStageClearSequence; // 0x24
    bool mDraw3D; // 0x28
    bool mIsPlayingWorldMapBGM; // 0x29
    bool mIsIslandFleetGalaxyFirstTime; // 0x2A
};

