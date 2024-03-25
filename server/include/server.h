/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** client.h
*/

#pragma once

#include "user.h"
#include "command.h"
#include "../../include/include.h"

typedef struct comment_s {

} comment_t;

typedef struct thread_s {
    comment_t **comments;
} thread_t;

typedef struct channel_s {
    thread_t **threads;
} channel_t;

typedef struct team_s {
    channel_t **channels;
} team_t;

typedef struct server_s {
    fd_set fd_set;
    socket_t socket;
    server_logger_t *logger;
    user_t *users[MAX_USER + 1];
} server_t;

int server(const int ac, const char **av);
int loop(server_t *server);

int read_stdin(server_t *server, int *is_running);

int load_server(server_t *server, const unsigned short port);
void unload_server(server_t *server);

int accept_conns(server_t *server);
