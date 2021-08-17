#pragma once

namespace MR
{
    template<typename T>
    class AssignableArray
    {
    public:
        ~AssignableArray();

        T** mContent; // _0
        s32 mSize; // _4
    };
};
