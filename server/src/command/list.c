/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** help.c
*/

#include "server.h"

static void list_teams(server_t *server, user_t *user)
{
    team_t *team;

    dprintf(user->nsock, "%d: %s\n", OK,  "List of teams:");
    for (unsigned int i = 0; i < server->teams->size(server->teams); i++) {
        team = server->teams->at(server->teams, i);
        dprintf(user->nsock, "     %s\n", team->name);
    }
}

static void loop_channel(user_t *user, channel_t *channel)
{
    thread_t *thread;

    for (unsigned int k = 0; k < channel->threads->size(channel->threads);
         k++) {
        thread = channel->threads->at(channel->threads, k);
        dprintf(user->nsock, "     %s\n", thread->name);
    }
}

static void list_channels(server_t *server, user_t *user)
{
    team_t *team;
    channel_t *channel;

    dprintf(user->nsock, "%d: %s\n", OK,  "List of channels:");
    for (unsigned int i = 0; i < server->teams->size(server->teams); i++) {
        team = server->teams->at(server->teams, i);
        for (unsigned int j = 0; j < team->channels->size(team->channels);
             j++) {
            channel = team->channels->at(team->channels, j);
            dprintf(user->nsock, "     %s\n", channel->name);
        }
    }
}

static void list_thread(server_t *server, user_t *user)
{
    team_t *team;
    channel_t *channel;

    dprintf(user->nsock, "%d: %s\n", OK,  "List of threads:");
    for (unsigned int i = 0; i < server->teams->size(server->teams); i++) {
        team = server->teams->at(server->teams, i);
        for (unsigned int j = 0; j < team->channels->size(team->channels);
             j++) {
            channel = team->channels->at(team->channels, j);
            loop_channel(user, channel);
        }
    }
}

static void list_reply(server_t *server, user_t *user)
{
    dprintf(user->nsock, "%d: %s\n", OK,  "List of reply:");
    dprintf(user->nsock,
        "%d: %s\n", NOT_IMPLEMENTED,  "Not implemented yet");
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
