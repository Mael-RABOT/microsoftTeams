/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** disconnect
*/

#include "server.h"

void disconnect(server_t *server)
{
    int i = 0;
    user_t *user = NULL;

    while (server->users[i] != NULL) {
        user = server->users[i];
        if (user->level == NOT_CONNECTED) {
            delete_user(user);
            shift_array((void **)server->users, i);
        }
        i += 1;
    }
}
