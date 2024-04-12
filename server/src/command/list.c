/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** help.c
*/

#include "server.h"

static void list_teams(server_t *server, user_t *user)
{
    dprintf(user->nsock, "%s\n", "List of teams:");
}

static void list_channels(server_t *server, user_t *user)
{
    dprintf(user->nsock, "%s\n", "List of channels:");
}

static void list_thread(server_t *server, user_t *user)
{
    dprintf(user->nsock, "%s\n", "List of thread:");
}

static void list_reply(server_t *server, user_t *user)
{
    dprintf(user->nsock, "%s\n", "List of reply:");
}

void list_command(server_t *server, user_t *user, packet_t *packet)
{
    context_t context = get_context(user);
    switch (context) {
        case NO_CONTEXT:
            return list_teams(server, user);
        case TEAM:
            return list_channels(server, user);
        case CHANNEL:
            return list_thread(server, user);
        case THREAD:
            return list_reply(server, user);
    }
}
