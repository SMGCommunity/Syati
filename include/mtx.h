#pragma once

#include "kamek.h"

#ifdef __cplusplus
extern "C" {
#endif

void PSMTXIdentity(Mtx matrix);
void PSMTXCopy(const Mtx sourceMtx, Mtx destMtx);
void PSMTXConcat(const Mtx sourceA, const Mtx sourceB, Mtx dest);
u32 PSMTXInverse(const Mtx source, Mtx dest);
u32 PSMTXInvXpose(const Mtx source, Mtx dest);
void PSMTXRotTrig(Mtx matrix, u8 axis, f32 sin, f32 cos);
// __PSMTXRotAxisRadInternal
void PSMTXRotAxisRad(Mtx matrix, Vec* axis, f32 radians);
void PSMTXTrans(Mtx matrix, f32 x, f32 y, f32 z);
void PSMTXTransApply(const Mtx source, Mtx dest, f32 x, f32 y, f32 z);
void PSMTXScale(Mtx matrix, f32 x, f32 y, f32 z);
void PSMTXScaleApply(const Mtx source, Mtx dest, f32 x, f32 y, f32 z);
void PSMTXQuat(Mtx dest, const Quaternion* quat);
void C_MTXLookAt(Mtx dest, const Vec* cameraPos, const Vec* cameraUp, const Vec* target);
void C_MTXLightPerspective(Mtx dest, f32 fovy, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT);
void C_MTXLightOrtho(Mtx dest, f32 top, f32 bottom, f32 left, f32 right, f32 scaleS, f32 scaleT, f32 transS, f32 transT);

// mtxvec
void PSMTXMultVec(const Mtx matrix, const Vec* source, Vec* dest);
// PSMTXMultVecSR
// PSMTXMultVecArraySR

// mtx44
void C_MTXPerspective(Mtx44 dest, f32 fovy, f32 aspect, f32 near, f32 far);
void C_MTXOrtho(Mtx44 dest, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far);
void PSMTXIdentity(Mtx44 matrix);
void PSMTXCopy(const Mtx44 sourceMtx, Mtx44 destMtx);

// vec
void PSVECAdd(const Vec* sourceA, const Vec* sourceB, Vec* dest);
void PSVECSubtract(const Vec* sourceA, const Vec* sourceB, Vec* dest);
void PSVECScale(const Vec* source, Vec* dest, f32 scale);
void PSVECNormalize(const Vec* source, Vec* dest);
// C_VECMag
f32 PSVECMag(const Vec* vec);
f32 PSVECDotProduct(const Vec* sourceA, const Vec* sourceB);
void PSVECCrossProduct(const Vec* sourceA, const Vec* sourceB, Vec* dest);
f32 PSVecDistance(const Vec* sourceA, const Vec* sourceB);

// quat
void PSQUATMultiply(const Quaternion* sourceA, const Quaternion* sourceB, Quaternion* dest);
f32 PSQUATDotProduct(const Quaternion* sourceA, const Quaternion* sourceB);
void C_QUATMtx(Quaternion* dest, const Mtx source);
void C_QUATSlerp(const Quaternion* sourceA, const Quaternion* sourceB, Quaternion* dest, f32 value);

#ifdef __cplusplus
}
#endif