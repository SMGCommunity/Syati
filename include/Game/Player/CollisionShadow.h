#pragma once

#include "Game/NameObj.h"
#include "Game/Player/J3DModelX.h"
#include "Game/Map/HitInfo.h"

class CollisionShadow : public NameObj {
public:
    CollisionShadow(f32, f32);
    ~CollisionShadow();

    void setMode(u32);
    void create(const TVec3f &, const TVec3f &, const TVec3f &);
    void sendVtx() const;
    TVec3f getDrawPos(u32) const;
    void sendZsortedVtx(bool) const;
    TVec3f getDrawPos(u32, u32) const;
    TVec2f getDrawTx(u32, u32) const;
    void initCaptureTex();
    void setUpdateFlag();
    void calcView(J3DModelX *, J3DModelX *);
    void drawAndCaptureTex(J3DModelX *, const TVec3f &);
    void clearAlphaBuffer();
    void drawVolumeBox(const TVec3f &, const TVec3f &) const;
    void draw() const;
    void draw1() const;
    void draw2() const;
    void draw3() const;
    void createDL();
    void drawVolume() const;
    void doSortPolygons();

    u8 _12;
    u16 _14;
    f32 _18;
    f32 _1C;
    f32 _20;
    f32 _24;
    f32 _28;
    TVec3f _2C;
    TVec3f _38;
    TVec3f _44;
    TVec3f _50;
    u32 _5C;
    u16 _60;
    u16 _62;
    u32 **_64;      // array at 803F2514
    TVec3f **_68;   // array at 803F24BC
    u32 **_6C;      // array at 803F24F0
    u32 **_70;      // array at 803F2508
    u16 _74;
    u16 _76;
    u8 _78[128];
    u32 _F8[128];
    TVec3f _2F8;
    u16 _304;
    u16 _306;
    u32 _308;
    u8 _30C;
    u8 _30D;
    u8 _30E;
    u8 _30F;
    u16 _310;
    f32 _314;
    f32 _318;
    TVec3f _31C;
    TVec3f _328;
    Triangle **_334;
    Triangle **_338;
    Triangle **_33C;
    u16 _340;
    u16 _342;
    u16 _344;
    u32 _348;
    u32 _34C;
    u16 _350;
};