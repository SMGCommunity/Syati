#pragma once

#include "revolution/types.h"

class LiveActor;
class J3DModel;
class J3DModelData;
class J3DMaterial;
class XanimeResourceTable;
class ResourceHolder;
class XanimePlayer;
struct ResTIMG;

namespace MR {
    void updateModelAnimPlayer(LiveActor*);
    void invalidateMtxCalc(J3DModelData*);
    void invalidateJointCallback(J3DModelData*);
    J3DModel* getJ3DModel(const LiveActor*); // Returns nullptr if not found
    void calcJ3DModel(LiveActor*);
    J3DModelData* getJ3DModelData(const LiveActor*); // Returns nullptr if not found
    J3DModelData* getJ3DModelData(const char*); // Returns nullptr if not found
    f32 getBckFrameMax(const LiveActor*, const char*);
    f32 getBrkFrameMax(const LiveActor*, const char*);
    f32 getBvaFrameMax(const LiveActor*, const char*);
    bool isBckPlaying(XanimePlayer*, const char*);

    s32 getMaterialNo(J3DModelData*, const char* pMatName);
    s32 getMaterialNo(J3DModel*, const char* pMatName);

    s32 getMaterialNum(const LiveActor*);
    s32 getMaterialNum(J3DModel*);
    const char* getMaterialName(const J3DModelData*, int);
    void updateModelDiffDL(LiveActor*);

    bool isEnvelope(J3DMaterial*);
    void hideMaterial(J3DModel*, const char*);
    void hideMaterial(const LiveActor*, const char*);
    void showMaterial(J3DModel*, const char*);
    void showMaterial(const LiveActor*, const char*);
    void calcFogStartEnd(TVec3f, f32, f32*, f32*);
    bool isUseTex(J3DMaterial*, u16);
    bool isNormalTexMtx(J3DMaterial*);
    bool isUseTexMtx(J3DMaterial*, u32);
    bool isExistEffectTexMtx(J3DModelData*);
    bool isExistEffectTexMtx(LiveActor*);
    bool isUseTexMtxEnvMap(J3DMaterial*);
    // Two functions between here that are only used by a Worldmap actor
    bool isUseTexMtxProjMap(J3DMaterial*);
    bool isUseFur(const J3DModelData*);
    void initEnvelopeAndEnvMapOrProjMapModelData(J3DModelData*);

    ResTIMG* getResTIMG(const LiveActor*, int);
    ResTIMG* getResTIMG(const J3DModelData*, int);




    void updateModelDiffDL(LiveActor*);

    void copyJointAnimation(LiveActor*, const LiveActor*);
    void syncJointAnimation(LiveActor*, const LiveActor*);
    void syncMaterialAnimation(LiveActor*, const LiveActor*);

    s32 getLightNumMax(const LiveActor* pActor);
    s32 getLightNumMax(J3DModelData*);
    void downFracVtx(J3DModelData*);
    void calcModelBoundingBox(TBox3f* pDest, const LiveActor* pActor);
    void calcModelBoundingRadius(f32* pDest, const LiveActor* pActor);
    bool isExistCollisionResource(const LiveActor *, const char *);
    bool isExistModel(const char* pName);
    bool isExistSubModel(const char* pName, const char* pSubName);




    XanimeResourceTable* newXanimeResourceTable(ResourceHolder*);
};
