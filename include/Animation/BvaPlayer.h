#pragma once

#include "JSystem.h"
#include "Animation/AnmPlayer.h"

class BvaPlayer : public AnmPlayerBase
{
public:
    BvaPlayer(const ResTable *, J3DModel *);

    void calc();
    bool getAnmVisibility();
};