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
    /**
      * \brief Prepares for drawing directly to the scene
      *
      * \param drawType The drawing type to use. 0 = No Textures. 1 = 1 Texture. 2 = 1 Texture w/ Alpha
      * \param blendType The drawing type to use. 0 = Opaque. 1 = Transparent. 2 = Transparent Grey???
      * \param projectionType The drawing type to use. 0 = Camera View. 1 = Projection Matrix. 2 = Screen (2D)
      * \param time The number of frames it takes to change to the new speed
      *
     **/
    static void setup(u32 drawType, u32 blendType, u8 projectionType);
    static void sendPoint(const TVec3f&, u32);
    static void sendPoint(const TVec3f& rPosition);
    static void drawLine(const TVec3f& rPositionA, const TVec3f& rPositionB, u32 color);
    static void drawCircle(const TVec3f& rPosition, const TVec3f& rFaceNormal, f32 radius, u32 color, u32 resolution);
    static void drawCircle(const TVec3f&, const TVec3f&, const TVec3f&, f32, u32, u32);
    static void drawFillCircle(const TVec3f&, f32, u32, u32, u32);
    static void drawFillCircle(const TVec3f&, const TVec3f&, f32, u32, u32);
    static void drawCylinder(const TVec3f& rBasePosition, const TVec3f& rTopOffset, f32 radius, u32 baseColor, u32 topColor, u32 resolution);
    static void drawSpherePart(const TMtx34f&, f32, f32, f32, f32, f32, u32, u32, u32);
    static void drawSphere(const TVec3f& rPosition, f32 radius, u32 color, u32 resolution);
    static void drawSphere3D(const TVec3f position, f32 radius, u32 color, u32 resolution);
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