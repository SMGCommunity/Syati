#pragma once

#include "Game/LiveActor.h"
#include "JSystem/J3DGraphBase/J3DModel.h"
#include "JSystem/JUtility/JUTTexture.h"

class FurCtrl;
class FurBank;
class FurParam;

class FurMulti {
public:
    FurMulti(LiveActor *, u32);
    void setLayerDirect(u32, u32, u32, u32, FurParam *, ResTIMG *, ResTIMG *, ResTIMG *, ResTIMG *);
    void addToManager();
    void offDraw(u32);
    void onDraw(u32);

    u8 _0;
    u8 _1;
    u8 _2;
    u8 _3;
    u32 **_4;
    u8 **_8;
    u32 _C;
    u32 _10;
    u32 _14;
    LiveActor *mActor; // _18
    J3DModel *mModel; // _1C
    u32 **_20;
};