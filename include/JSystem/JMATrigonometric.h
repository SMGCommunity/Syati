#pragma once

#include "revolution.h"

namespace std {
    template <typename A1, typename B1>
    struct pair {
        A1 a1;
        B1 b1;
        pair() {
            a1 = A1();
            b1 = B1();
        }
    };
}  // namespace std

namespace JMath
{
    const f32 PI = 3.1415927f;
    const f32 TWO_PI = 6.2831855f;

    template < int Bits, typename T >
    class TSinCosTable {
    public:
        static const u32 LEN = 1 << Bits;
        std::pair< T, T > table[LEN];

        T sinShort(s16 v) const { return table[static_cast<u16>(v) >> (16U - Bits)].a1; }
        T cosShort(s16 v) const { return table[static_cast<u16>(v) >> (16U - Bits)].b1; }

        inline f32 sinLapRad(f32 v) {
            if (v < 0.0f) {
                f32 tmp = v * (-LEN / TWO_PI);
                return -table[(u16)tmp & LEN - 1].a1;
            }
            else {
                f32 tmp = v * (LEN / TWO_PI);
                return table[(u16)tmp & LEN - 1].a1;
            }
        }

        inline f32 cosLapRad(f32 v) {
            if (v < 0.0f) {
                v = -v;
            }

            f32 tmp = v;
            tmp *= (LEN / TWO_PI);
            return table[(u16)tmp & LEN - 1].b1;
        }

        inline f32 cosLap(f32 v) {
            if (v < 0.0f) {
                v = -v;
            }
            // 45.511112f == LEN / TWO_PI * PI / 180
            v = 45.511112f * v;

            return table[(u16)v & LEN - 1].b1;
        }

        inline f32 get(f32 v) { return table[(u16)v & LEN - 1].b1; }
    };

    template<s32 Len, typename T>
    class TAtanTable
    {
    public:
        TAtanTable();

        T atan2_(T, T) const;
        T get_(T, T) const;

        T mTable[Len];
        T _1000;
    };

    template<s32 Len, typename T>
    class TAsinAcosTable
    {
    public:
        TAsinAcosTable();

        T get_(T, T) const;

        T mTable[Len];
        T _1000;
    };

    static TSinCosTable<14, f32> sSinCosTable;
    static TAtanTable<1024, f32> sAtanTable;
    static TAsinAcosTable<1024, f32> sAsinAcosTable;
};

inline f32 JMASSin(u16 s) {
    return JMath::sSinCosTable.sinShort(s);
}

inline f32 JMASCos(u16 s) {
    return JMath::sSinCosTable.cosShort(s);
}