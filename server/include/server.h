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
#include "input_command.h"
#include "../../include/include.h"

extern const bool completion;

typedef struct server_s {
    fd_set fd_set;
    queue_t *teams;
    queue_t *users;
    queue_t *accounts;
    socket_t socket;
    server_logger_t *logger;
    char history_path[PATH_MAX];
} server_t;
