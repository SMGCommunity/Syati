#pragma once

#include "JSystem/JGeometry.h"
#include "revolution/gx/GXStruct.h"

class J3DModelData;

namespace MR {
    void drawInit();
    void reinitGX();

    void setupShadowVolumeDraw();
    void resetTextureCacheSize();

    void drawSimpleModel(J3DModelData*);

    void reinitGX();

    void fillScreen(const _GXColor&);

    void fillScreenSetup(const _GXColor &);

    void fillScreenArea(const TVec2s &, const TVec2s &);

    void setupDrawForNW4RLayout(f32);

    void clearZBuffer();

    void setDefaultViewportAndScissor();

    void loadProjectionMtxFor2D();
};
