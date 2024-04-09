/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** help.c
*/

#include "server.h"

void help_command(server_t *server, user_t *user)
{
    user->send(user, "200 Help\n");
}
