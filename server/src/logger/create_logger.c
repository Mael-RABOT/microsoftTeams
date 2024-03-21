/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** logger.c
*/

#include "server.h"

static int load(logger_t *logger, int no_symbol, ...)
{
    va_list list;
    int index = 0;
    void *ptr = NULL;
    void *logger_ptr = logger;

    va_start(list, no_symbol);
    while (index < no_symbol) {
        ptr = logger->dlloader->load(logger->dlloader, va_arg(list, char *));
        if (ptr == NULL) {
            va_end(list);
            return 84;
        }
        memmove(logger_ptr + index * 8, &ptr, sizeof(ptr));
        index += 1;
    }
    va_end(list);
    return 0;
}

static int init_ptr(logger_t *logger)
{
    return load(logger, 11, "server_event_team_created",
        "server_event_channel_created", "server_event_thread_created",
        "server_event_reply_created", "server_event_user_subscribed",
        "server_event_user_unsubscribed", "server_event_user_created",
        "server_event_user_loaded", "server_event_user_logged_in",
        "server_event_user_logged_out", "server_event_private_message_sended");
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
    if (init_ptr(logger) == 84) {
        return NULL;
    }
    return logger;
}
