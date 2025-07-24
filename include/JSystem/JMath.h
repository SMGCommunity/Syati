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

	class TRandom_fast_ {
	public:
		TRandom_fast_(u32);

		inline u32 rand() {
			return mSeed = 0x19660D * mSeed + 0x3C6EF35F;
		}

		u32 mSeed;
	};
};

namespace JMathInlineVEC {
	void PSVECAdd(const Vec *srcA, const Vec *srcB, Vec *dest);
	void PSVECSubtract(const Vec *srcA, const Vec *srcB, Vec *dest);
    #ifdef __MWERKS__
    __attribute__((always_inline))
    inline f32 PSVECSquareDistance(const register Vec* a, const register Vec* b)
    {
        
        register f32 dyz, dxy, sqdist;
        register f32 v0xy, v1yz, v0yz, v1xy;
        
        asm
        {
            psq_l    v0yz, 4(a), 0, 0
            psq_l    v1yz, 4(b), 0, 0
            ps_sub   dyz, v0yz, v1yz
            
            psq_l    v0xy, 0(a), 0, 0
            psq_l    v1xy, 0(b), 0, 0
            ps_mul   dyz, dyz, dyz
            ps_sub   dxy, v0xy, v1xy
            
            ps_madd  sqdist, dxy, dxy, dyz
            ps_sum0  sqdist, sqdist, dyz, dyz
        }
        
        return sqdist;
    }
    
    __attribute__((always_inline))
    inline void PSVECAdd2(register const Vec* vec1, register const Vec* vec2, register Vec* dst) {
        register f32 v2z, d1z, v1z, v2xy, v1xy, d1xy;
        
        __asm {            
            psq_l     v1xy, 0(vec1), 0, 0
            psq_l     v2xy, 0(vec2), 0, 0
            ps_add    d1xy, v1xy, v2xy
            psq_l     v1z,   8(vec1), 1, 0
            psq_l     v2z,   8(vec2), 1, 0
            ps_add    d1z, v1z, v2z
            psq_st    d1xy, 0(dst), 0, 0
            psq_st    d1z,  8(dst), 1, 0
        }
    }
    #else
    f32 PSVECSquareDistance(const register Vec* a, const register Vec* b);
    void PSVECAdd2(register const Vec* vec1, register const Vec* vec2, register Vec* dst);
    #endif
};
