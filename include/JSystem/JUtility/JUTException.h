#pragma once

#include "revolution.h"
#include "JSystem/JUtility/JUTConsole.h"
class OSContext;

class JUTException {
public:
    enum EInfoPage {
        EINFOPAGE_0,
        EINFOPAGE_1
    };

    static void panic_f(const char *, s32, const char *, ...);
    void printDebugInfo(EInfoPage, u16, OSContext*, u32, u32);
    void showSRR0Map(OSContext*);

    static JUTConsole* sConsole;
};
