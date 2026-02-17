/*
SPCheats - Cheats for single-player without sv_cheats!
Copyright 2026
https://github.com/thecybermind/spcheats_qmm/
3-clause BSD license: https://opensource.org/license/bsd-3-clause

Created By:
    Kevin Masterson < k.m.masterson@gmail.com >

*/

#if defined(GAME_Q3A)

#include <qmmapi.h>

#include "version.h"
#include "game.h"

#include "util.h"
#include "main.h"


intptr_t GAME_vmMain(intptr_t cmd, intptr_t* args) {
    QMM_RET_IGNORED(0);
}


intptr_t GAME_syscall(intptr_t cmd, intptr_t* args) {
	if (cmd == G_GET_USERCMD) {
		// this is a good place to hook when a player respawns.
		// weird, i know, but if you look through ClientSpawn you'll
		// see this is called after the starting machine gun is set

		gclient_t* client = CLIENT_FROM_NUM(args[0]);

		// if the user just respawned, and he has a machine gun, we need to
		// remove it and give him a rocket launcher
		if (((client->ps.pm_flags & PMF_RESPAWNED) == PMF_RESPAWNED)
			&& ((client->ps.stats[STAT_WEAPONS] & (1 << WP_MACHINEGUN)) == (1 << WP_MACHINEGUN))
			&& QMM_GETINTCVAR("spcheats_enabled")	// moved this here to run it less
			) {

			gentity_t* ent = ENT_FROM_NUM(args[0]);
			if (!(ent->r.svFlags & SVF_BOT)) {
				client->ps.stats[STAT_MAX_HEALTH] = 500;
				client->ps.stats[STAT_HEALTH] = 1000;
				client->ps.stats[STAT_ARMOR] = 500;
				ent->health = 500;
				ent->flags |= FL_NO_KNOCKBACK | FL_GODMODE;
			}
		}
	}
	
	QMM_RET_IGNORED(0);
}


intptr_t GAME_vmMain_Post(intptr_t cmd, intptr_t* args) {
    QMM_RET_IGNORED(0);
}


intptr_t GAME_syscall_Post(intptr_t cmd, intptr_t* args) {
	QMM_RET_IGNORED(0);
}

#endif // GAME_Q3A
