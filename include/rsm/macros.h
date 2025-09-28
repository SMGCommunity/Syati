#pragma once

#define ATTRIBUTE_ALIGN(align) __attribute__((aligned(align)))
#define MOVE_REGISTER(var, reg) \ \
asm ( \
    mr var, reg; \
) \