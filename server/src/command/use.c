/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** use.c
*/

#include "prototype.h"

void use_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t uuid;

    uuid_parse(packet->args[0], uuid);
    if (user->context.team == NULL) {
        return;
    }
    if (user->context.channel == NULL) {
        user->context.channel = NULL;
        return;
    }
    if (user->context.thread == NULL) {
        return;
    }
}
