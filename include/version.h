/*
SPCheats - Cheats for single-player without sv_cheats!
Copyright 2026
https://github.com/thecybermind/spcheats_qmm/
3-clause BSD license: https://opensource.org/license/bsd-3-clause

Created By:
    Kevin Masterson < k.m.masterson@gmail.com >

*/

#ifndef SPCHEATS_QMM_VERSION_H
#define SPCHEATS_QMM_VERSION_H

#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x

#define SPCHEATS_QMM_VERSION_MAJOR		2
#define SPCHEATS_QMM_VERSION_MINOR		4
#define SPCHEATS_QMM_VERSION_REV		2

#define SPCHEATS_QMM_VERSION			STRINGIFY(SPCHEATS_QMM_VERSION_MAJOR) "." STRINGIFY(SPCHEATS_QMM_VERSION_MINOR) "." STRINGIFY(SPCHEATS_QMM_VERSION_REV)

#if defined(_WIN32)
#define SPCHEATS_QMM_OS        		"Windows"
#ifdef _WIN64
#define SPCHEATS_QMM_ARCH      		"x86_64"
#else
#define SPCHEATS_QMM_ARCH      		"x86"
#endif
#elif defined(__linux__)
#define SPCHEATS_QMM_OS        		"Linux"
#ifdef __LP64__
#define SPCHEATS_QMM_ARCH      		"x86_64"
#else
#define SPCHEATS_QMM_ARCH      		"x86"
#endif
#endif

#define SPCHEATS_QMM_VERSION_DWORD		SPCHEATS_QMM_VERSION_MAJOR , SPCHEATS_QMM_VERSION_MINOR , SPCHEATS_QMM_VERSION_REV , 0
#define SPCHEATS_QMM_COMPILE			__TIME__ " " __DATE__
#define SPCHEATS_QMM_BUILDER			"Kevin Masterson"

#endif // SPCHEATS_QMM_VERSION_H
