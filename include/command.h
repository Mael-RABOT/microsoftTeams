/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** command.h
*/

#pragma once

#include "include.h"

enum status_e {
    NOT_CONNECTED,
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
    BROADCAST,
    END
} command_type_t;

typedef enum codes_e {
    OK = 200,
    CREATED = 201,
    MESSAGE_RECEIVED = 202,
    MESSAGES_LIST = 203,
    CONNECTED = 220,
    DISCONNECTED = 221,

    BAD_REQUEST = 400,
    UNAUTHORIZED = 401,
    NOT_FOUND = 404,
    ALREADY_EXIST = 409,
    UNKNOWN_USER = 410,
    UNKNOWN_TEAM = 411,
    UNKNOWN_CHANNEL = 412,
    UNKNOWN_THREAD = 413,

    INTERNAL_ERROR = 500,
    NOT_IMPLEMENTED = 501
} codes_t;

typedef struct packet_s {
    command_type_t type;
    char **args;
} packet_t;

packet_t *create_packet(void);
void delete_packet(packet_t *packet);
