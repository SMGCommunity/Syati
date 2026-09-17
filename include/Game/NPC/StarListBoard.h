#pragma once

#include "Game/NPC/NPCActor.h"

class StarListBoard : public NPCActor {
public:
    StarListBoard(const char *pName);
    virtual ~StarListBoard();
    virtual void init(const JMapInfoIter &rIter);

    void eventFunc();
    void exeWait();
    void exeOpen();

    u32 _164;
};

namespace NrvStarListBoard {
    NERVE(StarListBoardNrvWait);
    NERVE(StarListBoardNrvOpen);
}