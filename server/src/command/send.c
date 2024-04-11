/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** login.c
*/

#include "prototype.h"

void send_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t target_uuid;
    bool found = false;

    if (uuid_parse(packet->args[0], target_uuid) == -1) {
        dprintf(user->nsock, "%d: %s\n", BAD_REQUEST, "Invalid UUID");
        return;
    }
    for (int i = 0; server->users[i] != NULL; i++) {
        if (uuid_compare(server->users[i]->uuid, target_uuid) == 0
            && server->users[i]->level >= LOGGED) {
            dprintf(server->users[i]->nsock, "%d: %s\n", OK, packet->args[1]);
            found = true;
        }
    }
    if (!found) {
        dprintf(user->nsock, "%d: %s\n", BAD_REQUEST, "User not found");
        return;
    }
    dprintf(user->nsock, "%d: %s\n", OK, "OK");
}
