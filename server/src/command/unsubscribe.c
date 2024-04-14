/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** unsubscribe.c
*/

#include "prototype.h"

static void unsubscribe_user(team_t *team, user_t *user)
{
    unsigned int i = 0;
    user_t *tmp_user = NULL;

    while (i < team->subscribed->size(team->subscribed)) {
        tmp_user = team->subscribed->at(team->subscribed, i);
        if (tmp_user == user) {
            team->subscribed->remove(team->subscribed, i);
            user->send(user, "200, You have unsubscribe from team\n");
            return;
        }
        i += 1;
    }
    user->send(user, "You are not subscribed to this team\n");
    return;
}

void unsubscribe_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t uuid;
    team_t *team = NULL;

    if (len_array((void **)packet->args) < 1) {
        user->send(user, "400 Bad arguments\n");
        return;
    }
    uuid_parse(packet->args[0], uuid);
    team = get_resource(server->teams, offsetof(team_t, uuid), uuid,
        (bool (*)(void *, void *))uuid_strict_compare);
    if (team == NULL) {
        user->send(user, "400 Cannot find team\n");
    } else {
        unsubscribe_user(team, user);
    }
}
