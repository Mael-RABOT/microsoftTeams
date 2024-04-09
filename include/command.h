/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** command.h
*/

#pragma once

#include "include.h"

enum status_e {
    DISCONNECTED,
    NOT_LOGGED,
    LOGGED
};

typedef enum command_type_e {
    ERROR = -1,
    TEXT = 0,
    HELP = 1,
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
    INFO,
    EXIT,
    END
} command_type_t;

typedef struct packet_s {
    command_type_t type;
    char **args;
} packet_t;

packet_t *create_packet(void);
void delete_packet(packet_t *packet);
