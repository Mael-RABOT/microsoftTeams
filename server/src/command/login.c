/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** login.c
*/

#include "server.h"

void login_command(server_t *server, user_t *user)
{
    if (len_array((void **)user->args) != 1) {
        user->send(user, "400 Invalid number of arguments");
    }
    strcpy(user->name, user->args[0]);
    user->level = LOGGED;
}
