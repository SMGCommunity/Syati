#pragma once

#include "revolution.h"

class GameEventFlag;
class GameEventFlagAccessor;

class GameEventFlagIter {
public:
    bool isEnd() const;
    void goNext();
    const GameEventFlag* getFlag() const;
    bool isValid() const;

    u32 mIter;  // _0
};

class GameEventFlagTableInstance {
public:
    GameEventFlagTableInstance();

    void initSortTable();
    GameEventFlag* findFlag(const char *);

    u32 _0;
    u32 _4;
};

class GameEventFlagTable {
public:
    static GameEventFlagIter getBeginIter();
    static s32 getTableSize();
    static const GameEventFlag* getFlag(int);
    static const GameEventFlag* findFlag(const char *);
    static bool isExist(const char *);
    static int getIndex(const GameEventFlag *);
    int getIndexFromHashCode(u16);
};