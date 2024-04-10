/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** channel.h
*/

#pragma once

#include "thread.h"

typedef struct channel_s {
    uuid_t uuid;
    queue_t *threads;
    void (*save)(struct channel_s *channel);
    void (*restore)(struct channel_s *channel);
} channel_t;

channel_t *create_channel(void);
void delete_channel(channel_t *channel);
