#pragma once

#include "Game/NameObj.h"
#include "Game/Util/JMapIdInfo.h"
#include "Game/Util/BothDirPtrList.h"

class StageDataArchiveHolder;
class PlacementInfoOrdered;

class StageDataHolder : public NameObj {
public:
    StageDataHolder(const char *, int, bool);
    ~StageDataHolder();
    virtual void init(const JMapInfoIter &);
    void initAfterScenarioSelected();
    void initFileLoadPostCreation();
    void initPlacement();
    JMapInfo getCommonPathPointInfo(const JMapInfo **, int) const;
    JMapInfo getCommonPathPointInfoFromRailDataIndex(const JMapInfo **, int) const;
    s32 getCommonPathInfoElementNum() const;
    s32 getStartPosNum() const;
    s32 getCurrentStartZoneId() const;
    s32 getCurrentStartCameraId() const;
    void getStartCameraIdInfoFromStartDataIndex(JMapIdInfo *, int) const;
    s32 getGeneralPosNum() const;
    JMapInfo *getGeneralPosInfoFromDataIndex(int) const;
    s32 getChildObjNum(const JMapInfoIter &) const;
    JMapInfo *getChildObjInfoFromDataIndex(const JMapInfoIter &, int) const;
    const StageDataHolder *findPlacedStageDataHolder(const JMapInfoIter &) const;
    const StageDataHolder *getStageDataHolderFromZoneId(int) const;
    const StageDataHolder *getStageDataHolderFromZoneId(int);
    bool isPlacedZone(int) const;
    const char *getJapaneseObjectName(const char *) const;
    void *getStageArchiveResource(const char *);
    s32 getStageArchiveResourceSize(void *);
    void initPlacementMario();
    JMapInfoIter makeMarioJMapInfoIter(const JMapIdInfo &) const;
    JMapInfoIter makeCurrentMarioJMapInfoIter() const;
    void initTableData();
    JMapInfo *findJmpInfoFromArray(const MR::AssignableArray<JMapInfo> *, const char *) const;
    JMapInfoIter getStartJMapInfoIterFromStartDataIndex(int) const;
    void calcDataAddress();
    void updateDataAddress(const MR::AssignableArray<JMapInfo> *);
    void createLocalStageDataHolder(const MR::AssignableArray<JMapInfo> &, bool);
    void calcPlacementMtx(const JMapInfoIter &);
    void initLayerJmpInfo(MR::AssignableArray<JMapInfo> *, const char *, const char *, u32);

    JMapInfo *mObjNameTbl;                  // _14
    u32 _18;
    StageDataHolder* mStageDataArray[0x18]; // _1C
    const char *_7C;
    Mtx mPlacementMtx;                      // _80
    s32 _B0;
    bool _B4;
    u32 _B8;
    u32 _BC;
    PlacementInfoOrdered *_C0;
    StageDataArchiveHolder *_C4;
    MR::BothDirPtrList _C8;
    MR::BothDirPtrList _D4;
    MR::BothDirPtrList _E0;
    MR::BothDirPtrList _EC;
};

namespace MR {
    StageDataHolder *getStageDataHolder();
}