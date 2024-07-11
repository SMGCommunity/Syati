#pragma once

#include "revolution.h"
#include "JSystem.h"
#include "Game/System/ResourceInfo.h"

class MaterialAnmBuffer;
class BckCtrl;

class ResourceHolder {
public:
    ResourceHolder(JKRArchive &, const char *);

    const char* getResName(u32) const;
    bool isExistMaterialAnim();

    // Note: taken from Petari but it should be accurate unless
    // it was rearranged
    ResTable* mModelResTable;           // _0
    ResTable* mMotionResTable;          // _4
    ResTable* mBtkResTable;             // _8
    ResTable* mBpkResTable;             // _C
    ResTable* mBtpResTable;             // _10
    ResTable* mBlkResTable;             // _14
    ResTable* mBrkResTable;             // _18
    ResTable* mBasResTable;             // _1C
    ResTable* mBmtResTable;             // _20
    ResTable* mBvaResTable;             // _24
    ResTable* mBanmtResTable;           // _28
    ResTable* mFileInfoTable;           // _2C
    ResTable mDefaultTable;             // _30
    MaterialAnmBuffer* mMaterialBuf;    // _38
    BckCtrl* mBckCtrl;                  // _3C
    void* mBackupMaterialData;          // _40
    JKRArchive* mArchive;               // _44
    JKRHeap* mHeap;                     // _48
    u32 _4C; // UNKNOWN
    const char *_50; // Archive Path?
};
