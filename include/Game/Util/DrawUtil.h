#pragma once

#include "revolution/gx/GXStruct.h"
#include "revolution.h"
#include "JSystem/JGeometry.h"

class J3DModelData;

namespace MR {
    void drawInit();
    void reinitGX();

    void setupShadowVolumeDraw();

    void drawSimpleModel(J3DModelData*);

    void reinitGX();

    void fillScreen(const _GXColor&);

    void fillScreenSetup(const _GXColor &);

    void fillScreenArea(const TVec2s &, const TVec2s &);

    void clearZBuffer();

    void setDefaultViewportAndScissor();
};
