#pragma once

#include "revolution.h"

f64 JMASinRadian(f32);
f64 JMASinDegree(f32);
f64 JMACosRadian(f32);
f64 JMACosDegree(f32);
f64 JMAAcosRadian(f32);
f64 JMASqrt(f32);
f64 JMAAsinRadian(f32);

void JMAEulerToQuat(s16 eulerX, s16 eulerY, s16 eulerZ, Quaternion *dest);
void JMAQuatLerp(const Quaternion *srcA, const Quaternion *srcB, f32 interpolant, Quaternion *dest);

void JMAVECScaleAdd(const Vec *srcForScaling, const Vec *srcAdd, Vec *dest, f32 scale);
void JMAVECLerp(const Vec *srcA, const Vec *srcB, Vec *dest, f32 t);
void JMAMTXApplyScale(const MtxPtr src, MtxPtr dest, f32 scaleX, f32 scaleY, f32 scaleZ);

namespace JMath {
	template<typename T>
	T fastSqrt(T x);

	f32 fastReciprocal(f32 x);

	void gekko_ps_copy12(void *dest, const void *src);
	void gekko_ps_copy16(void *dest, const void *src);
};

namespace JMathInlineVEC {
	void PSVECAdd(const Vec *srcA, const Vec *srcB, Vec *dest);
	void PSVECSubtract(const Vec *srcA, const Vec *srcB, Vec *dest);
};
