#pragma once 

#include "revolution.h"
#include "JSystem/JUtility/TColor.h"

class JUTConsole : public JKRDisposer {
public:

    void print(const char*);
    void print_f(const char*, ...);
    JUtility::TColor _C;
    s32 _10;
    s32 _14;
    s32 _18;
    s32 _1C;
    u32 mParam1;
    u32 mParam2;
    s32 _28;
    bool mParam3;
    s32 _30;
    s32 _34;
    s32 _38;
    s32 _3C;
    s32 _40;
    s32 _44;
    s32 _48;
    s32 _4C;
    s32 _50;
    s32 _54;
    s32 _58;
    s32 _5C;
    s32 _60;
    s32 _64;
    s32 _68;
};

const s32 test2 = sizeof(JUtility::TColor);