#pragma once

#include "revolution.h"

namespace MR {
    const wchar_t* getSystemMessageDirect(const char *pLabel);
    const wchar_t* getGameMessageDirect(const char *pLabel);
    const wchar_t* getSceneMessageDirect(const char *pLabel, s32 zoneId); //If you pass -1 as the zoneId, it will look in SceneCommonMessage!
};
