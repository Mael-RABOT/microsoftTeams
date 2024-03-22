/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** client.h
*/

#pragma once

#include "../../include/include.h"

typedef struct client_s {
    socket_t socket;
    client_logger_t *logger;
} client_t;

int client(const int ac, const char **av);
int loop(client_t *client);
