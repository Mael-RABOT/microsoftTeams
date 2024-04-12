/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** use.c
*/

#include "prototype.h"

static void use_thread(user_t *user, const char *arg)
{
    uuid_t uuid;
    void *resource = NULL;

    uuid_parse(arg, uuid);
    resource = get_resource(user->context.channel->threads,
        offsetof(thread_t, uuid), uuid,
        (bool (*)(void *, void *))uuid_strict_compare);
    if (resource == NULL) {
        user->send(user, "404 Cannot find resource\n");
    } else {
        user->send(user, "200 Context set\n");
        user->context.thread = resource;
    }
    return;
}

static void use_channel(user_t *user, const char *arg)
{
    uuid_t uuid;
    void *resource = NULL;

    uuid_parse(arg, uuid);
    resource = get_resource(user->context.team->channels,
        offsetof(channel_t, uuid), uuid,
        (bool (*)(void *, void *))uuid_strict_compare);
    if (resource == NULL) {
        user->send(user, "404 Cannot find resource\n");
    } else {
        user->send(user, "200 Context set\n");
        user->context.channel = resource;
    }
    return;
}

static void use_team(server_t *server, user_t *user, const char *arg)
{
    uuid_t uuid;
    void *resource = NULL;

    uuid_parse(arg, uuid);
    resource = get_resource(server->teams, offsetof(team_t, uuid),
        uuid, (bool (*)(void *, void *))uuid_strict_compare);
    if (resource == NULL) {
        user->send(user, "404 Cannot find resource\n");
    } else {
        user->send(user, "200 Context set\n");
        user->context.team = resource;
    }
    return;
}

static void reset_context(user_t *user)
{
    user->context.team = NULL;
    user->context.channel = NULL;
    user->context.thread = NULL;
}

void use_command(server_t *server, user_t *user, packet_t *packet)
{
    reset_context(user);
    if (len_array((void **)packet->args) == 0)
        return (void)dprintf(user->nsock, "%d: Context reset\n", OK);
    if (len_array((void **)packet->args) >= 1)
        use_team(server, user, packet->args[0]);
    if (len_array((void **)packet->args) >= 2)
        use_channel(user, packet->args[1]);
    if (len_array((void **)packet->args) >= 3)
        use_thread(user, packet->args[2]);
}
