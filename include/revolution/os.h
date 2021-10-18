#pragma once

#ifndef __REVOLUTION_OS_H
#define __REVOLUTION_OS_H

#ifdef __cplusplus
extern "C" {
#endif

void OSReport(const char *, ...);
void OSFatal(u32 *fg, u32 *bg, const char *str, ...);

#ifdef __cplusplus
}
#endif

#endif // __REVOLUTION_OS_H
