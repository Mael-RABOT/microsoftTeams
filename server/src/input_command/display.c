/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** display.c
*/

#include "server.h"

static void display_team(server_t *server)
{
    unsigned int i = 0;

    while (i < server->teams->size(server->teams)) {
        printf("New team\n");
        i += 1;
    }
}

void display(server_t *server)
{
    int i = 0;

    printf("Connected user(s): %d\n", len_array((void **)server->users));
    while (server->users[i] != NULL) {
        i += 1;
    }
    display_team(server);
}
