/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create_channel.c
*/

#include "prototype.h"

channel_t *create_channel(void)
{
    channel_t *channel = malloc(sizeof(channel_t));

    if (channel == NULL) {
        return NULL;
    }
    memset(channel, 0, sizeof(channel_t));
    channel->threads = create_queue();
    if (channel->threads == NULL) {
        free(channel);
        return NULL;
    }
    uuid_generate(channel->uuid);
    return channel;
}
