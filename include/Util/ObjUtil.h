#pragma once

#include "JGeometry/TVec3.h"

class NameObj;
class LiveActor;

namespace MR
{
    void connectToSceneMapObj(LiveActor *);
    void connectToSceneMapObjMovement(NameObj *);
    void connectToSceneEnemy(LiveActor *);
    void connectToSceneEnemyMovement(NameObj *);
    void connectToSceneNpc(LiveActor *);

    void connectToSceneMapObjNoMovement(LiveActor *);

    void registerNameObjToExecuteHolder(NameObj *, int, int, int, int);

    bool isStageStateScenarioOpeningCamera();

    bool tryRumblePadMiddle(const void *, s32);
    bool tryRumblePadWeak(const void *, s32);

    void shakeCameraVeryStrong();
    void shakeCameraStrong();
    void shakeCameraNormalStrong();
    void shakeCameraWeak();
    void shakeCameraVeryWeak();

    void declareStarPiece(const NameObj *, s32);
    void appearStarPiece(const NameObj *, const JGeometry::TVec3<f32> &, s32, f32, f32, bool);
};