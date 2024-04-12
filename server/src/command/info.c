/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** help.c
*/

#include "server.h"

static void info_user(user_t *user)
{
    char uuid[37];

    uuid_unparse(user->uuid, uuid);
    dprintf(user->nsock,
        "%d: User name: %s\n     User uuid: %s\n", OK, user->name, uuid);
}

static void info_team(user_t *user)
{
    char uuid[37];

    uuid_unparse(user->context.team->uuid, uuid);
    dprintf(user->nsock,
        "%d: Team name: %s\n     Team uuid: %s\n", OK,
        user->context.team->name, uuid);
}

static void info_channel( user_t *user)
{
    char uuid[37];

    uuid_unparse(user->context.channel->uuid, uuid);
    dprintf(user->nsock,
        "%d: Channel name: %s\n     Channel uuid: %s\n", OK,
        user->context.channel->name, uuid);
}

static void info_thread(user_t *user)
{
    char uuid[37];

    uuid_unparse(user->context.thread->uuid, uuid);
    dprintf(user->nsock,
        "%d: Thread name: %s\n     Thread uuid: %s\n", OK,
        user->context.thread->name, uuid);
}

void info_command(server_t *server, user_t *user, packet_t *packet)
{
    context_t context = get_context(user);
    switch (context) {
        case NO_CONTEXT:
            return info_user(user);
        case TEAM:
            return info_team(user);
        case CHANNEL:
            return info_channel(user);
        case THREAD:
            return info_thread(user);
    }
}
