#pragma once

#include "Game/Util/JMapInfo.h"
#include "Game/Map/HitInfo.h"

class CodeTable {
public:
    CodeTable(u32);

    void add(const char *, u32);
    const char *getString(u32);

    u32 mNumCodes;          // _0
    u32 mMaxNumCodes;       // _4
    u32 *mHashCodes;        // _8
    u32 *_C;
    const char **mNames;    // _10
};

class CollisionCode {
public:
    CollisionCode();
    void createFloorTable();
    void createWallTable();
    void createSoundTable();
    void createCameraTable();

    u32 getFloorCode(const JMapInfoIter &);
    const char *getFloorCodeString(const Triangle &);
    u32 getWallCode(const JMapInfoIter &);
    const char *getWallCodeString(const Triangle &);
    u32 getSoundCode(const JMapInfoIter &);
    const char *getSoundCodeString(const Triangle &);
    const char *getSoundCodeString(const JMapInfoIter &);
    u32 getCameraCode(const JMapInfoIter &);
    u32 getCameraID(const Triangle &);
    u32 getCameraID(const JMapInfoIter &);
    u32 getCode(const JMapInfoIter &, CodeTable *, const char *);

    CodeTable *mFloorTable;     // _0
    CodeTable *mWallTable;      // _4
    CodeTable *mSoundTable;     // _8
    CodeTable *mCameraTable;    // _C
};