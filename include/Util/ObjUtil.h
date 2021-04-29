#pragma once

#include "JGeometry/TVec3.h"
#include "kamek.h"

class NameObj;
class LiveActor;

namespace MR
{
    void connectToScene(NameObj *, int, int, int, int);
    void connectToSceneCollisionMapObj(LiveActor *);
    void connectToSceneCollisionMapObjWeakLight(LiveActor *);
    void connectToSceneCollisionMapObjStrongLight(LiveActor *);
    void connectToSceneCollisionEnemy(LiveActor *);
    void connectToSceneCollisionEnemyStrongLight(LiveActor *);
    void connectToSceneCollisionEnemyNoShadowedMapObjStrongLight(LiveActor *);
    void connectToSceneNpc(LiveActor *);
    void connectToSceneNpcMovement(LiveActor *);
    void connectToSceneRide(LiveActor *);
    void connectToSceneEnemy(LiveActor *);
    void connectToSceneEnemyMovement(NameObj *);
    void connectToSceneMapObj(LiveActor *);
    void connectToSceneMapObjMovement(NameObj *);
    void connectToSceneMapObjMovementCalcAnim(NameObj *);
    void connectToSceneMapObjNoMovement(LiveActor *);
    void connectToSceneMapObjNoCalcAnim(LiveActor *);
    void connectToSceneMapObjNoCalcAnimStrongLight(LiveActor *);
    void connectToSceneMapObjDecoration(LiveActor *);
    void connectToSceneMapObjDecorationStrongLight(LiveActor *);
    void connectToSceneMapObjDecorationMovement(NameObj *);
    void connectToSceneMapObjStrongLight(LiveActor *);
    void connectToScenePlanet(LiveActor *);
    void connectToSceneEnvironment(LiveActor *);
    void connectToSceneEnvironmentStrongLight(LiveActor *);
    void connectToClippedMapParts(LiveActor *);
    void connectToSceneEnemyDecoration(LiveActor *);
    void connectToSceneEnemyDecorationMovement(NameObj *);
    void connectToSceneEnemyDecorationMovementCalcAnim(NameObj *);
    void connectToSceneItem(LiveActor *);
    void connectToSceneItemStrongLight(LiveActor *);
    void connectToSceneIndirectEnemy(LiveActor *);
    void connectToSceneIndirectNpc(LiveActor *);
    void connectToSceneIndirectMapObj(LiveActor *);
    void connectToSceneIndirectMapObjStrongLight(LiveActor *);
    void connectToSceneScreenEffectMovement(NameObj *);
    void connectToSceneAreaObj(NameObj *);
    void connectToScene3DModelFor2D(LiveActor *);
    void connectToSceneLayout(NameObj *);

    void connectToSceneTalkLayout(NameObj *);
    void connectToSceneWipeLayout(NameObj *);

    void connectToSceneLayoutMovement(NameObj *);
    void connectToSceneMirrorMapObj(LiveActor *);
    void connectToSceneMirrorMapObjDecoration(LiveActor *);
    void connectToSceneCamera(NameObj *);
    void connectToSceneNoShadowedMapObj(LiveActor *);
    void connectToSceneNoShadowedMapObjStrongLight(LiveActor *);
    void connectToSceneNoSilhouettedMapObj(LiveActor *);
    void connectToSceneNoSilhouettedMapObjStrongLight(LiveActor *);

    void connectToSceneSky(LiveActor *);
    void connectToSceneAir(LiveActor *);
    void connectToSceneSun(LiveActor *);

    /* These are wrong in SMG2, to be removed
    void registerNameObjToExecuteHolder(NameObj *, int, int, int, int);

    bool isStageStateScenarioOpeningCamera();*/

    void declarePowerStar(const NameObj *);
    void declarePowerStar(const NameObj *, s32);
    void declarePowerStarCoin100();
    void appearPowerStarContinueCurrentDemo(const NameObj *, const JGeometry::TVec3<f32> &);
    void appearPowerStarWithoutDemo(const NameObj *);

    void requestAppearPowerStar(const NameObj *, const JGeometry::TVec3<f32> &);
    void requestAppearPowerStar(const NameObj *, s32, const JGeometry::TVec3<f32> &);
    void requestAppearPowerStar(const NameObj *, const LiveActor *, f32);

    void requestAppearPowerStarCoin100();
    bool isEndPowerStarAppearDemo(const NameObj *);
    NameObj* createPowerStarDemoModel(const NameObj *, const char *, Mtx);

    void declareCoin(const NameObj*, s32);
    s32 getDeclareRemnantCoinCount(const NameObj *);

    bool hopCoin(const NameObj *, const JGeometry::TVec3<f32> &, const JGeometry::TVec3<f32> &);
    bool appearCoinPop(const NameObj *, const JGeometry::TVec3<f32> &, s32);
    bool appearCoinPopToDirection(const NameObj *, const JGeometry::TVec3<f32> &, const JGeometry::TVec3<f32> &, s32);

    bool appearCoinToVelocity(const NameObj *, const JGeometry::TVec3<f32> &, const JGeometry::TVec3<f32> &, s32);
    bool appearCoinCircle(const NameObj *, const JGeometry::TVec3<f32> &, const JGeometry::TVec3<f32> &, s32);
    void declareStarPiece(const NameObj *, s32);
    s32 getDeclareRemnantStarPieceCount(const NameObj *);
    s32 getDeclareRemnantStarPieceCountNotExist(const NameObj *);
    void declareStarPieceReceiver(const NameObj *, s32);
    void clearGotCountStarPieceReceiver(const NameObj *);
    bool hopStarPiece(const NameObj *, const JGeometry::TVec3<f32> &, const JGeometry::TVec3<f32> &);
    bool appearStarPiece(const NameObj *, const JGeometry::TVec3<f32> &, s32, f32, f32, bool);
    bool appearStarPieceToDirection(const NameObj *, const JGeometry::TVec3<f32> &, const JGeometry::TVec3<f32> &, s32, f32, f32, bool);

    void initStarPieceGetCSSound();

    void stopScene(s32);
    void stopSceneForDefaultHit(s32);
    bool tryRumblePad(const void *, const char *, s32);
    bool tryRumblePadVeryStrongLong(const void *, s32);
    bool tryRumblePadStrong(const void *, s32);
    bool tryRumblePadMiddle(const void *, s32);
    bool tryRumblePadWeak(const void *, s32);
    bool tryRumblePadVeryWeak(const void *, s32);

    bool tryRumbleDefaultHit(const void *, s32);

    void shakeCameraVeryStrong();
    void shakeCameraStrong();
    void shakeCameraNormalStrong();
    void shakeCameraNormal();
    void shakeCameraNormalWeak();
    void shakeCameraWeak();
    void shakeCameraVeryWeak();
    void shakeCameraInfinity(NameObj *, f32, f32);
    void stopShakingCamera(NameObj *);
    bool isName(const NameObj *, const char *);
    bool isSame(const NameObj *, const NameObj *);
};
