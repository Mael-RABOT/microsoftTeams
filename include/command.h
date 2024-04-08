/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** command.h
*/

#pragma once

#define NO_COMMAND  14

enum status_e {
    DISCONNECTED,
    NOT_LOGGED,
    LOGGED
};

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

struct command_s {
    enum command_type type;
    int no_args;
    enum status_e required;
};

struct packet_s {
    enum command_type type;
};

extern struct command_s command_lists[NO_COMMAND];
