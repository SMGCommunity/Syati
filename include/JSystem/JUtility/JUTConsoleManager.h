#pragma once

#include "revolution.h"

class JUTConsoleManager {
    public:
    void drawDirect(bool) const;

    s32 _0;
    s32 _4;
    s32 _8;
    s32 _C;
    s32 _10;

    static JUTConsoleManager* sManager;
};