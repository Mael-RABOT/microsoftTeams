/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** login.c
*/

#include "prototype.h"

void logout_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->level < LOGGED)
        return (void)dprintf(
            user->nsock, "%d Not logged in\n", BAD_REQUEST);
    user->level = NOT_LOGGED;
    server->logger->user_logged_out(user->account->uuid_str);
    dprintf(user->nsock, "%d: %s\n", DISCONNECTED, "Disconnected");
}
