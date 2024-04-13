/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** subscribed.c
*/

#include "prototype.h"

void display_subscribed(void *arg)
{
    user_t *user = (user_t *)arg;

    user->send(user, "200 %s is subsribed\n", user->name);
}

void subscribed_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t uuid;

    if (len_array((void **)packet->args) == 1) {
        uuid_parse(packet->args[0], uuid);
        team_t *team = (team_t *)get_resource(server->teams,
            offsetof(team_t, uuid), uuid,
            (bool (*)(void *, void *))uuid_strict_compare);
        if (team != NULL) {
            team->subscribed->foreach(team->subscribed, display_subscribed);
        }
    } else {

    }
}
