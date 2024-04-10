/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** login.c
*/

#include "server.h"

void login_command(server_t *server, user_t *user, packet_t *packet)
{
    if (len_array((void **)packet->args) < 1) {
        dprintf(user->nsock, "400 Bad arguments\n");
        return;
    }
    user->level = LOGGED;
    strcpy(user->name, packet->args[0]);
    dprintf(user->nsock, "200 Ok\n");
}
