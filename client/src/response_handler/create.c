/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** loop.c
*/

#include "client.h"

static void handle_thread_creation(client_t *client, char **data)
{
    time_t timestamp = atol(data[4]);

    client->logger->client_event_thread_created(
        data[1], data[2], timestamp, data[3], data[5]);
}

void create_handler(client_t *client, codes_t code, char *response)
{
    char **data;

    if (code != CREATED)
        return;
    data = split(response, ":");
    if (!data)
        return;
    if (strcmp(data[0], "Team") == 0)
        client->logger->client_event_team_created(data[1], data[2], data[3]);
    if (strcmp(data[0], "Channel") == 0)
        client->logger->client_event_channel_created(
            data[1], data[2], data[3]);
    if (strcmp(data[0], "Thread") == 0)
        handle_thread_creation(client, data);
    delete_array((void **)data);
}
