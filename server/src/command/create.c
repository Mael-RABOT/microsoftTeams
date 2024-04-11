/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create.c
*/

#include "prototype.h"

static void create_resource(queue_t *dest, void **context, void *(*func)())
{
    void *resource = func();

    *context = resource;
    dest->push_back(dest, resource);
}

void create_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->context.team == NULL) {
        create_resource(server->teams, (void **)&user->context.team,
            (void *(*)())&create_team);
        return;
    }
    if (user->context.channel == NULL) {
        create_resource(user->context.team->channels,
            (void **)&user->context.channel, (void *(*)())&create_channel);
        return;
    }
    if (user->context.thread == NULL) {
        create_resource(user->context.channel->threads,
            (void **)&user->context.thread, (void *(*)())&create_thread);
        return;
    }
    return;
}
