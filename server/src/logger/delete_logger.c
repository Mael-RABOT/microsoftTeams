/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** delete_logger.c
*/

#include "server.h"

void delete_logger(logger_t *logger)
{
    if (logger == NULL) {
        return;
    }
    delete_dlloader(logger->dlloader);
    free(logger);
}
