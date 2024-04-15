/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** subscribe.c
*/

#include "prototype.h"

void subscribe_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t uuid;
    team_t *team = NULL;

    if (len_array((void **)packet->args) < 1) {
        user->send(user, "400 bad arguments\n");
    }
    uuid_parse(packet->args[0], uuid);
    team = (team_t *)get_resource(server->teams,
        offsetof(team_t, uuid),
        uuid, (bool (*)(void *, void *))uuid_strict_compare);
    if (team != NULL) {
        team->subscribed->push_back(team->subscribed, user);
        user->send(user, "200 subscribed !\n");
    } else {
        user->send(user, "400 bad uuid\n");
    }
}
