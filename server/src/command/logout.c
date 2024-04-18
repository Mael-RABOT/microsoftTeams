/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** login.c
*/

#include "server_prototype.h"

void logout_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->level < LOGGED)
        return (void)user->send(user, "%d Not logged in\n", BAD_REQUEST);
    user->level = NOT_LOGGED;
    server_event_user_logged_out(user->account->uuid_str);
    user->send(user, "%d: %s\n", DISCONNECTED, "Disconnected");
}
