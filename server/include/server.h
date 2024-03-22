/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** client.h
*/

#pragma once

#include "../../include/include.h"

typedef struct {
    socket_t socket;
    server_logger_t *logger;
} server_t;

int server(const int ac, const char **av);
int loop(server_t *server);
void write_log(const char *str);
