#pragma once

#include "syati.h"

void JMAEulerToQuat(s16 eulerX, s16 eulerY, s16 eulerZ, Quaternion * dest);
void JMAQuatLerp(const Quaternion * srcA, const Quaternion * srcB, f32 interpolant, Quaternion * dest);
void JMAVECScaleAdd(const Vec * srcForScaling, const Vec * srcAdd, Vec * dest, f32 scale);
void JMAVECLerp(const Vec * srcForScaling, const Vec * srcAdd, Vec * dest, f32);
void JMAMTXApplyScale(const MtxPtr src, MtxPtr dest, f32 scaleX, f32 scaleY, f32 scaleZ);

namespace JMath
{
	template<typename T>
	T fastSqrt(T x);

	f32 fastReciprocal(f32 x);

	void gekko_ps_copy12(void * dest, const void * src);
	void gekko_ps_copy16(void * dest, const void * src);
};

namespace JMathInlineVEC
{
	void PSVECAdd(const Vec * srcA, const Vec * srcB, Vec * dest);
	void PSVECSubtract(const Vec * srcA, const Vec * srcB, Vec * dest);
};
