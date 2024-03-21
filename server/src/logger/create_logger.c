/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** logger.c
*/

#include "server.h"

static void init_ptr(logger_t *logger)
{
    logger->team_created = LOAD("server_event_team_created");
    logger->channel_created = LOAD("server_event_channel_created");
    logger->thread_created = LOAD("server_event_thread_created");
    logger->reply_created = LOAD("server_event_reply_created");
    logger->user_subscribed = LOAD("server_event_user_subscribed");
    logger->user_unsubscribed = LOAD("server_event_user_unsubscribed");
    logger->user_created = LOAD("server_event_user_created");
    logger->user_loaded = LOAD("server_event_user_loaded");
    logger->user_logged_in = LOAD("server_event_user_logged_in");
    logger->user_logged_out = LOAD("server_event_user_logged_out");
    logger->private_message_sended =
        LOAD("server_event_private_message_sended");
}

logger_t *create_logger(const char *path)
{
    logger_t *logger = malloc(sizeof(logger_t));

    if (logger == NULL) {
        return NULL;
    }
    logger->dlloader = create_dlloader(path);
    if (logger->dlloader == NULL) {
        free(logger);
        return NULL;
    }
    init_ptr(logger);
    return logger;
}
