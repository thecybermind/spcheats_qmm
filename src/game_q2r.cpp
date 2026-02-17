/*
SPCheats - Cheats for single-player
Copyright 2026
https://github.com/thecybermind/spcheats_qmm/
3-clause BSD license: https://opensource.org/license/bsd-3-clause

Created By:
    Kevin Masterson < k.m.masterson@gmail.com >

*/

#if defined(GAME_Q2R)

#include <qmmapi.h>

#include "version.h"
#include "game.h"

#include "util.h"
#include "main.h"

// ignore G_INFO_VALUEFORKEY if inside GAME_CLIENT_USERINFO_CHANGED
static bool s_in_client_userinfo_changed = false;
/*
// pointer to start of item list
static gitem_t* s_itemlist = nullptr;


// find entity by userinfo pointer
gentity_t* FindEntityByUserinfo(const char* userinfo) {
    int i = 0;
    gentity_t* ent = nullptr;
    while (i < g_numgents) {
        ent = ENT_FROM_NUM(i);
        i++;

        if (!ent->client || !ent->inuse)
            continue;
        // gi.Info_ValueForKey(ent->client->pers.userinfo, "fov", val, sizeof(val));
        if (ent->client->pers.userinfo == userinfo)
            return ent;
    }

    return nullptr;
}


// find item in s_itemlist by classname
gitem_t* FindItemByClassname(const char* classname) {
    if (!s_itemlist)
        return nullptr;

    // skip the first blank entry
    gitem_t* item = s_itemlist + 1;
    while (item->classname) {
        if (!strcmp(item->classname, classname))
            return item;
        item++;
    }

    return nullptr;
}
*/

intptr_t GAME_vmMain(intptr_t cmd, intptr_t* args) {
    // we use G_INFO_VALUEFORKEY with a key of "fov" to determine if a user has respawned. but that is also checked
    // inside ClientUserinfoChanged. so we set a flag to ignore it in GAME_CLIENT_USERINFO_CHANGED and clear in _Post
    if (cmd == GAME_CLIENT_USERINFO_CHANGED) {
        s_in_client_userinfo_changed = true;
    }

    QMM_RET_IGNORED(0);
}


intptr_t GAME_syscall(intptr_t cmd, intptr_t* args) {
    // this is called with "fov" as key in PutClientInServer after initialization and before ChangeWeapon.
    // this is also called in ClientUserinfoChanged but we ignore that one
    if (cmd == G_INFO_VALUEFORKEY && !s_in_client_userinfo_changed && QMM_GETINTCVAR("spcheats_enabled")) {
/*
        // pointer to rocket launcher item
        static gitem_t* item_rocketlauncher = nullptr;

        // gi.Info_ValueForKey(ent->client->pers.userinfo, "fov", val, sizeof(val));
        const char* userinfo = (const char*)args[0];
        const char* key = (const char*)args[1];

        // skip if key is not "fov"
        if (strcmp(key, "fov") != 0)
            QMM_RET_IGNORED(0);

        // we need to check each entity to see which has this userinfo string
        gentity_t* ent = FindEntityByUserinfo(userinfo);

        // make sure ent is not null, it is in use, and has a client
        if (!ent || !ent->inuse || !ent->client)
            QMM_RET_IGNORED(0);

        // make sure ent is a player
        if (strcmp(ent->classname, "player") != 0)
            QMM_RET_IGNORED(0);

        // most everything after this references the client persistant data, so get a shortcut
        client_persistant_t* pers = &ent->client->pers;

        // make sure client is not a spectator
        if (pers->spectator)
            QMM_RET_IGNORED(0);

        // find the rocketlauncher item based on first spawned player's blaster:
        // the item list starts and ends with empty gitem_t objects, so grab a valid pointer to a blaster,
        // and scan back to the beginning null entry. then use FindItemByClassname to find items in the list
        if (!item_rocketlauncher) {
            gitem_t* item_weapon = pers->weapon;
            if (item_weapon) {
                gitem_t* item = item_weapon;
                // go back to the beginning of the item list
                while (item->classname)
                    item--;
                // save for lookups
                s_itemlist = item;
                // look up item
                item_rocketlauncher = FindItemByClassname("weapon_rocketlauncher");
            }
        }

        // still couldn't find rocketlauncher item, cancel
        if (!item_rocketlauncher) {
            QMM_RET_IGNORED(0);
        }

        // remove everything from inventory
        pers->inventory.fill(0);
        // set inventory count for rocket launcher to 1
        pers->inventory[IT_WEAPON_RLAUNCHER] = 1;
        // set weapon to rocket launcher gitem_t
        pers->weapon = item_rocketlauncher;
        // set ammo to cvar (cap at max)
        int start_ammo = (int)QMM_GETINTCVAR("spcheats_ammo");
        if (start_ammo > pers->max_ammo[AMMO_ROCKETS])
            start_ammo = pers->max_ammo[AMMO_ROCKETS];
        pers->inventory[IT_AMMO_ROCKETS] = start_ammo;
        // give chainfist if gauntlet cvar is enabled
        if (QMM_GETINTCVAR("spcheats_gauntlet"))
            pers->inventory[IT_WEAPON_CHAINFIST] = 1;
*/
    }
    QMM_RET_IGNORED(0);
}


intptr_t GAME_vmMain_Post(intptr_t cmd, intptr_t* args) {
    // we use G_INFO_VALUEFORKEY with a key of "fov" to determine if a user has respawned. but that is also checked
    // inside ClientUserinfoChanged. so we set a flag to ignore it in GAME_CLIENT_USERINFO_CHANGED and clear in _Post
    if (cmd == GAME_CLIENT_USERINFO_CHANGED) {
        s_in_client_userinfo_changed = false;
    }

    QMM_RET_IGNORED(0);
}


intptr_t GAME_syscall_Post(intptr_t cmd, intptr_t* args) {
    QMM_RET_IGNORED(0);
}

#endif // GAME_Q2R
