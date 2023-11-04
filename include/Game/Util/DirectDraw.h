#pragma once

#include "JSystem/JGeometry.h"

class JUTTexture;

class TDDraw {
public:
    static void setViewMtx(Mtx);
    static void loadViewMtx(Mtx);
    static void setModelMtx(Mtx);
    static void resetViewMtx();
    static void close();
    static void setup(u32, u32, u8);
    static void sendPoint(const TVec3f&, u32);
    static void sendPoint(const TVec3f&);
    static void drawLine(const TVec3f&, const TVec3f&, u32);
    static void drawCircle(const TVec3f&, const TVec3f&, f32, u32, u32);
    static void drawCircle(const TVec3f&, const TVec3f&, const TVec3f&, f32, u32, u32);
    static void drawFillCircle(const TVec3f&, f32, u32, u32, u32);
    static void drawFillCircle(const TVec3f&, const TVec3f&, f32, u32, u32);
    static void drawCylinder(const TVec3f&, const TVec3f&, f32, u32, u32, u32);
    static void drawSpherePart(const TMtx34f&, f32, f32, f32, f32, f32, u32, u32, u32);
    static void drawSphere(const TVec3f&, f32, u32, u32);
    static void drawSphere3D(const TVec3f, f32, u32, u32);
    static void drawTexture(const TVec2f&, JUTTexture*, const TVec2f&);
    static void drawTexture3D(const TVec3f&, const TVec3f&, const TVec3f&, f32, f32, JUTTexture*, bool, bool);
    static void drawFillBox(const TVec3f&, const TVec3f&, u32);
    static void drawFillBox(const TVec2f&, const TVec2f&, u32);
    static void drawFillBox3D(const TVec3f&, const TVec3f&, const TVec3f&, const TVec3f&, u32);
    static void cameraInit3D();
    static void cameraInit2D();
    static void mixFogColor(TVec3f, f32, u32);
    static void setGXColor(u32, GXColor* rColor);
    static void invProject(TVec3f*, const TVec3f&, Mtx, const f32*, const f32*, bool);
    static void project2D(TVec3f*, const TVec3f&);
    static void project2D(TVec2f*, const TVec3f&);
    static void fix2DPos(TVec3f*);
};