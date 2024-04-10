/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create_channel.c
*/

#include "channel.h"

channel_t *create_channel(void)
{
    channel_t *channel = malloc(sizeof(channel_t));

    if (channel == NULL) {
        return NULL;
    }
    channel->threads = NEW(queue);
    if (channel->threads == NULL) {
        free(channel);
        return NULL;
    }
    uuid_generate(channel->uuid);
    return channel;
}
