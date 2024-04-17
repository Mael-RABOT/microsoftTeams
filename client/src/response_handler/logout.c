/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** loop.c
*/

#include "client_prototype.h"

void logout_handler(client_t *client, codes_t code, char *response)
{
    (void)response;
    if (code != DISCONNECTED)
        return;
    client->logger->client_event_logged_out(
        client->user_uuid, client->username);
}
