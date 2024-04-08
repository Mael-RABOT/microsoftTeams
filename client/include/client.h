/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** client.h
*/

#pragma once

#include "../../include/include.h"
#include "../../libs/command/include/command.h"

typedef struct client_s {
    socket_t socket;
    client_logger_t *logger;
} client_t;

typedef struct command_map_s {
    char *input;
    command_type_t command_type;
} command_map;

int client(const int ac, const char **av);
int loop(client_t *client);

int load_client(client_t *client, const unsigned int address,
    const unsigned short port);
void unload_client(client_t *client);
