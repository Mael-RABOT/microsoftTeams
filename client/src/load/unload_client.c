/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** unload_client.c
*/

#include "client.h"

void unload_client(client_t *client)
{
    if (client == NULL) {
        return;
    }
    if (client->logger != NULL) {
        delete_client_logger(client->logger);
    }
    free(client->username);
    free(client->user_uuid);
}
