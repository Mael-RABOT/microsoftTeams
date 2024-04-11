/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** delete_channel.c
*/

#include "prototype.h"

void delete_channel(channel_t *channel)
{
    if (channel == NULL) {
        return;
    }
    if (channel->threads != NULL) {
        delete_queue(channel->threads);
    }
    free(channel);
}
