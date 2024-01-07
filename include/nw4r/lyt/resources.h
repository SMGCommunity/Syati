#pragma once

#include "revolution\types.h"
#include "nw4r\math\types.h"
#include "types.h"

namespace nw4r
{

namespace lyt
{

namespace res 
{

struct DataBlockHeader {
    char kind[4];
    u32 size;
};

struct Pane
{
    DataBlockHeader blockheader;
    u8 flag;
    u8 basePosition;
    u8 alpha;
    u8 padding;

    char name[16];
    char userData[8];
    math::VEC3 translate;
    math::VEC3 rotate;
    math::VEC2 scale;
    Size size;
};


}

}

}