/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** command.h
*/

#pragma once

enum command_type {
    HELP,
    LOGIN,
    LOGOUT,
    USERS,
    USER,
    SEND,
    MESSAGES,
    SUBSCRIBE,
    SUBSCRIBED,
    UNSUBSCRIBE,
    USE,
    CREATE,
    LIST,
    INFO
};

struct command {
    enum command_type type;
    int no_args;
};

struct command commands[14] = {
    {HELP, 1}
};

typedef struct command_s {
    enum command_type type;
} command_t;
