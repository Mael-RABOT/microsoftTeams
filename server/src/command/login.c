/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** login.c
*/

#include "server.h"

void login_command(server_t *server, user_t *user, packet_t *packet)
{
    user->level = LOGGED;
}
