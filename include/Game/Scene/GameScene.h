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
    void requestEndMissDemo();
    void requestPowerStarGetDemo();
    void requestGrandStarGetDemo();
    void requestStartSuperDreamerTalk();
    void requestEndSuperDreamerTalk();
    void setNerveAfterPauseMenu();
    bool isExecAction() const;
    bool isExecScenarioOpeningCamera() const;
    bool isExecScenarioStarter() const;
    bool isExecStageClearDemo() const;
    bool isExecSuperDreamerTalk() const;
    void permitsStartPauseMenu() const;
    bool isExecPauseMenu() const;
    void startStagePlayFirst();
    void startStagePlayRetry();
    void exeScenarioOpeningCamera();
    void exeSaveAfterGameOver();
    void exeAction();
    void initSequences();
    void initEffect();
    void drawMirror() const;
    void draw3D() const;
    void draw2D() const;
    bool isValidScenarioOpeningCamera() const;
    void startWorldMapBgm() const;
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

