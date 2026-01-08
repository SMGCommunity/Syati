#pragma once

#include "Game/Util/JMapInfo.h"
#include "Game/Util/Array.h"

class AlreadyDoneInfo {
public:
    AlreadyDoneInfo();

    void clear();
    void init(const char* pInfo, s32 placedZoneId, s32 linkId);
    bool isEqual(const AlreadyDoneInfo&) const;
    void on();

    u16 mNameAndValue; // 0x00 : MR::getHashCode(pInfo) & 0x7FFF. 0x8000 is used as the "set" value
    s32 mPlacedZoneId; // 0x04 : the zone ID that this flag belongs to
    s32 mLinkId;       // 0x08 : the Link ID of the object this flag belongs to
};

class AlreadyDoneFlagInGalaxy {
public:
    AlreadyDoneFlagInGalaxy(int); // Vanilla game uses 0x60 (96)

    void clear();
    bool setupFlag(int* outIndex, const char* name, const JMapInfoIter& rIter); // shortcut for setupFlag(outIndex, name, MR::getPlacedZoneId(rIter), <out MR::getJMapInfoLinkID>);
    void onFlag(const char* name);
    void onFlag(int index);
    bool isOnFlag(const char* name);
    void initInStageFlags();
    bool setupFlag(int* outIndex, const char* name, s32 placedZoneId, s32 linkId);
    AlreadyDoneInfo& tryGetInfo(const char* name);
    AlreadyDoneInfo& tryGetInfo(int index);

    MR::AssignableArray<AlreadyDoneInfo> mAlreadyDoneFlags; // 0x00 : The array of flags (96 entries long in vanilla)
    u32 mNumFlags;                                          // 0x08 : The number of flags in the array currently being used
};