#pragma once

#include "kamek.h"
#include "Actor/NameObj/NameObj.h"
#include "JMap/JMapInfoIter.h"

class StageSwitchCtrl
{
public:
    StageSwitchCtrl(const JMapInfoIter &);

    bool isValidSwitchAppear() const;

    u8 _0[0x10];
};

namespace MR
{
    StageSwitchCtrl* createStageSwitchCtrl(NameObj *, const JMapInfoIter &);
};