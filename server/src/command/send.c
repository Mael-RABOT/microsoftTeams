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
    user_t *dest_user = NULL;

    if (uuid_parse(packet->args[0], target_uuid) == -1) {
        dprintf(user->nsock, "%d: %s\n", BAD_REQUEST, "Invalid UUID");
        return;
    }
    dest_user = get_resource(server->users, offsetof(user_t, uuid),
        target_uuid, (bool (*)(void *, void *))uuid_strict_compare);
    if (dest_user == NULL) {
        dprintf(user->nsock, "%d: %s\n", BAD_REQUEST, "User not found");
    } else {
        dprintf(dest_user->nsock, "%d: %s\n", OK, packet->args[1]);
    }
    dprintf(user->nsock, "%d: %s\n", OK, "OK");
}
