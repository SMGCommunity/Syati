#pragma once

#include "revolution/types.h"

namespace MR {
    class ProhibitSchedulerAndInterrupts {
    public:
        ProhibitSchedulerAndInterrupts(bool unused);

        ~ProhibitSchedulerAndInterrupts();

        int mInterruptsStatus;
    };
};  // namespace MR
