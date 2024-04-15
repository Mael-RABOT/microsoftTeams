/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** login.c
*/

#include "prototype.h"

static int get_uuid(user_t *user)
{
    char **data = load_file(USER_FILE);
    char **line = NULL;

    if (!data)
        return 1;
    for (int i = 0; data[i] != NULL; i++) {
        line = split(data[i], " \n");
        if (strcmp(line[0], user->name) == 0) {
            uuid_parse(line[1], user->uuid);
            delete_array((void **)line);
            delete_array((void **)data);
            return 0;
        }
        delete_array((void **)line);
    }
    delete_array((void **)data);
    return 1;
}

void login_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->level >= LOGGED)
        return (void)dprintf(
            user->nsock, "%d Already logged in\n", BAD_REQUEST);
    if (len_array((void **)packet->args) < 1)
        return (void)dprintf(user->nsock, "%d Bad arguments\n", BAD_REQUEST);
    user->level = LOGGED;
    strcpy(user->name, packet->args[0]);
    if (get_uuid(user) == 1)
        create_uuid(user);
    uuid_unparse(user->uuid, uuid_str);
    dprintf(user->nsock, "%d: %s: %s\n", OK, user->name, uuid_str);
}
