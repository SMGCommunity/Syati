#pragma once

#include "JSystem/JKernel/JKRDisposer.h"

class JUTGamePad : public JKRDisposer {
public:
    enum EPadPort {
        Port_Unknown = -1,
        Port_1,
        Port_2,
        Port_3,
        Port_4,
    };
};