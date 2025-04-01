#pragma once

#include "syati.h"

// ctor at 0x80403890
// Player modes are the columns, properties are in the first field of each row

class MarioConstTable : public NameObj {
public:
    MarioConstTable(const char *pName, s32 numProperties, const char **pProperties, s32 numPlayerModes, const char **pPlayerModes, const char **pColumnKeys);
    void initialize(const char *pMarioConstArc, const char *pTableName);

    s32 mNumProperties;                     // _14
    const char **mProperties;               // _18
    s32 mNumPlayerModes;                    // _1C
    const char **mPlayerModes;              // _20
    const char **mColumnKeys;               // _24
    u8 *mTable;                             // _28
    HashSortTable *mPropertyHashSortTable;  // _2C
    HashSortTable *mPlayerModeHashSortTable;// _30
};