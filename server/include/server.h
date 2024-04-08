/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** client.h
*/

#pragma once

#define HISTORY_PATH    ".myteams_history"

#include "user.h"
#include "command.h"
#include "../../include/include.h"

char *completion_detect_word(const char *buf);
char *my_readline(const char *prompt);

typedef struct server_s {
    fd_set fd_set;
    socket_t socket;
    server_logger_t *logger;
    user_t *users[MAX_USER + 1];
    char history_path[PATH_MAX];
} server_t;

int server(const int ac, const char **av, const char **env);
int loop(server_t *server);

int read_stdin(server_t *server, int *is_running);

int load_server(server_t *server, const unsigned short port);
int load_server_history(const char **env, server_t *server);
void unload_server(server_t *server);

int accept_conns(server_t *server);
