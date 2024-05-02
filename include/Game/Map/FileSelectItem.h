
#pragma once

#include "revolution.h"
#include "Game/LiveActor/PartsModel.h"
#include "Game/LiveActor/LiveActor.h"
#include "Game/Map/FileSelectIconID.h"
#include "Game/Map/FileSelectModel.h"

class FileSelectItem : public LiveActor
{
public:
    struct FileSelectModelArray
    {
        FileSelectModel *mModels[7];
    };
    void createFellows();
    char _90[0x4];
    PartsModel *mPartsModel;          // _94
    const FileSelectIconID &mIconID;  // _98
    FileSelectModelArray *mModelArray; // _9C
    LiveActor *_A0;                   // MiiFaceParts
    char _A4[0x4];
    TMtx34f _A8;
    TMtx34f _D8;
    TMtx34f _108;
    char _138[0x13];
    bool mIsComplete; // _14B
    char _14C[0x174 - 0x14C];
};