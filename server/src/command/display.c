/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** display.c
*/

#include "server.h"

void display(server_t *server)
{
    int i = 0;

    while (server->users[i] != NULL) {
        i += 1;
    }
}
