#pragma once

namespace nw4r {
    namespace ut {
        namespace {

            template <typename T>
            inline T
            Min(T a, T b)
            {
                return (a > b) ? b: a;
            }

            template <typename T>
            inline T
            Max(T a, T b)
            {
                return (a < b) ? b: a;
            }


        };
    };
};