/*
SPCheats - Cheats for single-player
Copyright 2026
https://github.com/thecybermind/spcheats_qmm/
3-clause BSD license: https://opensource.org/license/bsd-3-clause

Created By:
    Kevin Masterson < k.m.masterson@gmail.com >

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>


// "safe" strncpy that always null-terminates
char* strncpyz(char* dest, const char* src, size_t count) {
	char* ret = strncpy(dest, src, count);
	dest[count - 1] = '\0';
	return ret;
}
