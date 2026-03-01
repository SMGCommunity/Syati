#pragma once

#include "JSystem/JKernel/JKRArchive.h"

class StageDataArchiveHolder {
public:
    StageDataArchiveHolder(const char *pStageName);
    JKRArchive *mountArchive(const char *pStageName, const char *pType);

    JKRArchive *mMap;           // _0
    JKRArchive *mSound;         // _4
    JKRArchive *mDesign;        // _8
    JKRArchive *mZoneInfo;      // _C
    JKRArchive *mUseResource;   // _10
    JKRArchive *mGhost;         // _14
};