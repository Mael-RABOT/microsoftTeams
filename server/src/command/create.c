/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create.c
*/

#include "prototype.h"

static void create_resource(queue_t *dest, void *(*func)())
{
    void *resource = func();

    dest->push_back(dest, resource);
}

void create_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->context.team == NULL) {
        create_resource(server->teams, (void *(*)())&create_team);
        user->send(user, "200 Ok\n");
        return;
    }
    if (user->context.channel == NULL) {
        create_resource(user->context.team->channels,
            (void *(*)())&create_channel);
        user->send(user, "200 Ok\n");
        return;
    }
    if (user->context.thread == NULL) {
        create_resource(user->context.channel->threads,
            (void *(*)())&create_thread);
        user->send(user, "200 Ok\n");
        return;
    }
    return;
}
