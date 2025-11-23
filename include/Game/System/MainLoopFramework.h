#pragma once

#include "revolution.h"

class MainLoopFramework {
public:
    void ctor_subroutine(bool);
    ~MainLoopFramework();
    static MainLoopFramework* createManager(const GXRenderModeObj*, void*, void*, void*, bool);
    void prepareCopyDisp();
    void drawendXfb_single();
    void exchangeXfb_double();
    void exchangeXfb_triple();
    void copyXfb_triple();
    void preGX();
    void endGX();
    void waitForRetrace();
    void beginRender();
    void endRender();
    void endFrame();
    void waitBlanking(int);
    void setTickRateFromFrame(u16);
    void clearEfb(GXColor);
    void clearEfb(int, int, int, int, GXColor);
    void calcCombinationRatio();
    static u32 frameToTick(f32);
    static void setForOSResetSystem();

    u8 _0[0x14];
    u32 mTickDuration;

    static MainLoopFramework* sManager;
};