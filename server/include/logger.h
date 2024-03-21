/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** server_logger.h
*/

#pragma once

#include "server.h"

#define CSTR    const char *

typedef struct logger_s {
    int (*team_created)(CSTR, CSTR, CSTR);
    int (*channel_created)(CSTR, CSTR, CSTR);
    int (*thread_created)(CSTR, CSTR, CSTR, CSTR, CSTR);
    int (*reply_created)(CSTR, CSTR, CSTR);
    int (*user_subscribed)(CSTR, CSTR);
    int (*user_unsubscribed)(CSTR, CSTR);
    int (*user_created)(CSTR, CSTR);
    int (*user_loaded)(CSTR, CSTR);
    int (*user_logged_in)(CSTR);
    int (*user_logged_out)(CSTR);
    int (*private_message_sended)(CSTR, CSTR, CSTR);
    dlloader_t *dlloader;
} logger_t;

logger_t *create_logger(const char *path);
void delete_logger(logger_t *logger);
