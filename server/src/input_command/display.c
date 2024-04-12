/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** display.c
*/

#include "prototype.h"

static void display_team(server_t *server)
{
    char uuid[64];
    unsigned int i = 0;

    while (i < server->teams->size(server->teams)) {
        uuid_unparse(server->teams->at(server->teams, i), uuid);
        printf("Team: %s\n", uuid);
        i += 1;
    }
}

void display(server_t *server)
{
    unsigned int i = 0;
    user_t *user = NULL;
    char uuid[37];

    printf("Connected user(s): %d\n", server->users->size(server->users));
    while (i < server->users->size(server->users)) {
        user = server->users->at(server->users, i);
        printf("\tContext:\n");
        uuid_unparse(user->uuid, uuid);
        if (user->context.team != NULL)
            printf("\t\tTeam: %s\n", uuid);
        i += 1;
    }
    display_team(server);
}
