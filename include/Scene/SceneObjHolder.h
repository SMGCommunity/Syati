#pragma once

class NameObj;

enum SceneObjType
{
	SceneObj_SensorHitChecker,
	SceneObj_CollisionDirector,
	SceneObj_ClippingDirector,
	SceneObj_DemoDirector,
	SceneObj_EventDirector,
	SceneObj_EffectSystem,
	SceneObj_LightDirector,
	SceneObj_SceneDataInitializer,
	SceneObj_StageDataHolder,
	SceneObj_MessageSensorHolder,
	SceneObj_StageSwitchContainer, // 10
	SceneObj_SwitchWatcherHolder,
	SceneObj_AwakeControllerHolder,
	SceneObj_AreaObjContainer,
	SceneObj_LiveActorGroupArray,
	SceneObj_MovementOnOffGroupHolder,
	SceneObj_CaptureScreenActor,
	SceneObj_AudCameraWatcher,
	SceneObj_AudEffectDirector,
	SceneObj_AudBgmConductor,
	SceneObj_ActionSoundSystem, // 20
	SceneObj_MarioHolder,
	SceneObj_Deleted_22,
	SceneObj_MirrorCamera,
	SceneObj_CameraContext,
	SceneObj_IgnorePauseNameObj,
	SceneObj_TalkDirector,
	SceneObj_EventSequencer,
	SceneObj_StopSceneController,
	SceneObj_SceneNameObjMovementController,
	SceneObj_ImageEffectSystemHolder, // 30
	SceneObj_BloomEffect,
	SceneObj_BloomEffectSimple,
	SceneObj_ScreenBlurEffect,
	SceneObj_DepthOfFieldBlur,
	SceneObj_PostFog,
	SceneObj_PostOutline,
	SceneObj_SceneWipeHolder,
	SceneObj_PlayerActionGuidance,
	SceneObj_LensFlareDirector,
	SceneObj_FurDrawManager, // 40
	SceneObj_PlacementStateChecker,
	SceneObj_NamePosHolder,
	SceneObj_NPCDirector,
	SceneObj_ResourceShare,
	SceneObj_WarpPodMgr,
	SceneObj_CenterScreenBlur,
	SceneObj_47, // スイッチ切り替えエフェクト
	SceneObj_48, // 時間停止画面取り込みテクスチャ
	SceneObj_49, // 時間停止画面エフェクト
	SceneObj_50, // 50; スイングアクション監視者
	SceneObj_51, // ワールドマップ
	SceneObj_52, // ワールドマップ（リザルト指揮）
	SceneObj_53, // スコアアタックアクセサ
	SceneObj_54, // スコア表示保持
	SceneObj_55, // 郵便屋さんシステム
	SceneObj_56, // サポートプレイ指揮
	SceneObj_AllLiveActorGroup,
	SceneObj_CameraDirector,
	SceneObj_PlanetGravityManager,
	SceneObj_BaseMatrixFollowTargetHolder, // 60
	SceneObj_GameSceneLayoutHolder,
	SceneObj_Deleted_62,
	SceneObj_CoinHolder,
	SceneObj_PurpleCoinHolder,
	SceneObj_CoinRotater,
	SceneObj_AirBubbleHolder,
	SceneObj_KarikariDirector,
	SceneObj_StarPieceDirector,
	SceneObj_BegomanAttackPermitter,
	SceneObj_BigFanHolder, // 70
	SceneObj_Deleted_71,
	SceneObj_Deleted_72,
	SceneObj_Deleted_73,
	SceneObj_KabokuriFireHolder,
	SceneObj_TakoheiInkHolder,
	SceneObj_76, // ShadowControllerParam
	SceneObj_77, // 影色セット
	SceneObj_ShadowVolumeDrawInit,
	SceneObj_ShadowSurfaceDrawInit,
	SceneObj_SwingRopeGroup, // 80
	SceneObj_PlantStalkDrawInit,
	SceneObj_PlantLeafDrawInit,
	SceneObj_TrapezeRopeDrawInit,
	SceneObj_Deleted_84,
	SceneObj_SpinDriverPathDrawInit,
	SceneObj_NoteGroup,
	SceneObj_ClipAreaDropHolder,
	SceneObj_FallOutFieldDraw,
	SceneObj_ClipFieldFillDraw,
	SceneObj_Deleted_90, // 90
	SceneObj_ClipAreaHolder,
	SceneObj_92, // 雪足場管理
	SceneObj_ClipAreaLightFruit,
	SceneObj_ScreenAlphaCapture,
	SceneObj_MapPartsRailGuideHolder,
	SceneObj_SpinCloudBlockGroup,
	SceneObj_GCapture,
	SceneObj_SupportTico,
	SceneObj_NameObjExecuteHolder,
	SceneObj_ElectricRailHolder, // 100
	SceneObj_SpiderThread,
	SceneObj_QuakeEffectGenerator,
	SceneObj_BowserBattleAccessor,
	SceneObj_Deleted_104,
	SceneObj_Deleted_105,
	SceneObj_HeatHazeDirector,
	SceneObj_YellowChipHolder,
	SceneObj_EarthenPipeMediator,
	SceneObj_PetitPorterMediator,
	SceneObj_Deleted_110, // 110
	SceneObj_WaterAreaHolder,
	SceneObj_WaterPlantDrawInit,
	SceneObj_RaceManager,
	SceneObj_GroupCheckManager,
	SceneObj_WaterPressureBulletHolder,
	SceneObj_FirePressureBulletHolder,
	SceneObj_SunshadeMapHolder,
	SceneObj_MiiFacePartsHolder,
	SceneObj_MiiFaceIconHolder,
	SceneObj_FluffWindHolder, // 120
	SceneObj_GalaxyNamePlateDrawer,
	SceneObj_CinemaFrame,
	SceneObj_Deleted_123,
	SceneObj_124, // プレイヤー追随パス
	SceneObj_InfernoMarioManager,
	SceneObj_PlanetMapCreator,
	SceneObj_ProductMapCreator,
	SceneObj_PriorDrawAirHolder,
	SceneObj_InformationObserver,
	SceneObj_StaffRoll, // 130
	SceneObj_MapPartsHolder,
	SceneObj_StarLightAreaHolder,
	SceneObj_133, // 切り替えオブジェホルダー
	SceneObj_DrillHoleHolder,
	SceneObj_CollectTicoHolder,
	SceneObj_IceMeteorHolder,
	SceneObj_137, // 絵本瞬間移動デモ
	SceneObj_PopoStickingManager,
	SceneObj_KoopaJrCastleAccessor,
	SceneObj_KoopaJrCastleWindHolder, // 140
	SceneObj_GliderShooterBulletHolder,
	SceneObj_GhostAttackManager,
	SceneObj_GliBirdTutorial,
	SceneObj_PauseBlur,
	SceneObj_StarPieceFlowerController,
	SceneObj_WoodBoxExterminationFlagHolder,
	SceneObj_MarioFaceShipSwitch,
	SceneObj_148, // 注目会話デモ指示者
	SceneObj_149, // Npc紹介デモ参加者ホルダー
	SceneObj_150, // 150; 会話デモ指示者
	SceneObj_MarioFaceShipEventDataHolder,
	SceneObj_WiiMessageBoardMailSender
};

class SceneObjHolder
{
public:
	SceneObjHolder();

	NameObj* create(int);
	NameObj* getObj(int) const;
	bool isExist(int) const;
	NameObj* newEachObj(int);

	NameObj* mSceneObjs[153];
};

namespace MR
{
	NameObj* createSceneObj(int);
	SceneObjHolder* getSceneObjHolder();
	bool isExistSceneObj(int);
};
