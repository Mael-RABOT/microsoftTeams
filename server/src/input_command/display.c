/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** display.c
*/

#include "prototype.h"

static void display_channel(server_t *server, team_t *team)
{
    unsigned int i = 0;
    channel_t *channel = NULL;

    while (i < team->channels->size(team->channels)) {
        channel = team->channels->at(team->channels, i);
        printf("    Channel: ");
        display_uuid(channel->uuid);
        printf("\n");
        i += 1;
    }
}

static void display_team(server_t *server)
{
    unsigned int i = 0;
    team_t *team = NULL;

    while (i < server->teams->size(server->teams)) {
        team = server->teams->at(server->teams, i);
        printf("Team: ");
        display_uuid(team->uuid);
        printf("\n");
        display_channel(server, team);
        i += 1;
    }
}

static void display_user(server_t *server)
{
    unsigned int i = 0;
    user_t *user = NULL;

    while (i < server->users->size(server->users)) {
        user = server->users->at(server->users, i);
        printf("User: \n");
        if (user->context.team != NULL) {
            printf("\tTeam: ");
            display_uuid(user->context.team->uuid);
            printf("\n");
        }
        if (user->context.channel != NULL) {
            printf("\tChannel: ");
            display_uuid(user->context.channel->uuid);
            printf("\n");
        }
        if (user->context.thread != NULL) {
            printf("\tThread: ");
            display_uuid(user->context.channel->uuid);
            printf("\n");
        }
        i += 1;
    }
}

void display(server_t *server)
{
    printf("Connected user(s): %d\n", server->users->size(server->users));
    display_user(server);
    display_team(server);
}
