/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** logger.c
*/

#include "server.h"

dlloader_t *init_logger(const char *path)
{
    dlloader_t *dlloader = create_dlloader(path);

    if (dlloader == NULL) {
        return NULL;
    }
    return dlloader;
}
