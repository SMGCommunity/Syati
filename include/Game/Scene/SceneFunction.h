#pragma once

#include "revolution/types.h"
#include "Game/Scene/Scene.h"
#include "Game/NameObj/NameObjCategories.h"

namespace SceneFunction {
    void startStageFileLoad();
    void waitDoneStageFileLoad();
    void startActorFileLoadCommon();
    void startActorFileLoadScenario();
    void startActorPlacement();
    void initAfterScenarioSelected();
    void initForNameObj();
    void initForLiveActor();
    void initEffectSystem(u32, u32);
    void allocateDrawBufferActorList();
    void createHioBasicNode(Scene*);
    void movementStopSceneController();
    void executeMovementList();
    void executeDrawList2DNormal();
    void executeDrawList2DMovie();
    void executeDrawBufferListNormalOpaBeforeVolumeShadow();
    void executeDrawSilhouetteAndFillShadow();
    void executeDrawAlphaShadow();
    void executeDrawBufferListNormalOpa();
    void executeDrawListOpa();
    void executeDrawBufferListNormalXlu();
    void executeDrawListXlu();
    void executeDrawAfterIndirect();
    void executeDrawImageEffect();
    void executeDrawBufferListNormalOpaBeforeSilhouette();
    void executeCalcAnimListOnPlayingMovie();
    void executeCalcAnimList();
    void executeCalcViewAndEntryList();
    void executeMovementListOnPlayingMovie();
};

namespace CategoryList {
    static void execute(MR::MovementType);
    static void execute(MR::CalcAnimType);
    static void execute(MR::DrawType);
    static void entryDrawBuffer2D();
    static void entryDrawBuffer3D();
    static void entryDrawBufferMirror();
    static void drawOpa(MR::DrawBufferType);
    static void drawXlu(MR::DrawBufferType);
    static void requestMovementOn(MR::MovementType);
    static void requestMovementOff(MR::MovementType);
};