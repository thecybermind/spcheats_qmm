/*
SPCheats - Cheats for single-player
Copyright 2004-2026
https://github.com/thecybermind/spcheats_qmm/
3-clause BSD license: https://opensource.org/license/bsd-3-clause

Created By:
    Kevin Masterson < k.m.masterson@gmail.com >

*/

#ifndef SPCHEATS_QMM_UTIL_H
#define SPCHEATS_QMM_UTIL_H

#include <vector>
#include <string>

// "safe" strncpy that always null-terminates
char* strncpyz(char* dest, const char* src, size_t count);

#endif // SPCHEATS_QMM_UTIL_H
