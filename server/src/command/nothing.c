/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** nothing.c
*/

#include "server_prototype.h"

void nothing_command(server_t *server, user_t *user, packet_t *packet)
{
    dprintf(user->nsock, "%d: Not implemented\n", NOT_IMPLEMENTED);
    return;
}
