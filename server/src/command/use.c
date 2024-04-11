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

    uuid_parse(arg, uuid);
    void *resource = get_resource(user->context.channel->threads,
        offsetof(thread_t, uuid), uuid,
        (bool (*)(void *, void *))uuid_strict_compare);
    user->context.team = resource;
    return;
}

static void use_channel(user_t *user, const char *arg)
{
    uuid_t uuid;

    uuid_parse(arg, uuid);
    void *resource = get_resource(user->context.team->channels,
        offsetof(channel_t, uuid), uuid,
        (bool (*)(void *, void *))uuid_strict_compare);
    user->context.team = resource;
    return;
}

static void use_team(server_t *server, user_t *user, const char *arg)
{
    uuid_t uuid;

    uuid_parse(arg, uuid);
    void *resource = get_resource(server->teams, offsetof(team_t, uuid),
        uuid, (bool (*)(void *, void *))uuid_strict_compare);
    if (resource == NULL) {
        printf("NULL");
    } else {
        user->context.team = resource;
        printf("Okey");
    }
    return;
}

void use_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->context.team == NULL) {
        printf("Context is null\n");
    }
    printf("Ok");
    if (user->context.team == NULL && (len_array((void **)packet->args) >= 1)) {
        printf("Setting team context");
        use_team(server, user, packet->args[0]);
        return;
    }
    if (user->context.channel == NULL && len_array((void **)packet->args) >= 2) {
        use_channel(user, packet->args[1]);
        return;
    }
    if (user->context.thread == NULL && len_array((void **)packet->args) >= 3) {
        use_thread(user, packet->args[2]);
        return;
    }
}
