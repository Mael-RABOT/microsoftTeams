/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** thread.h
*/

#pragma once

#include "../../include/include.h"
#include "message.h"

struct user_s;
struct channel_s;

typedef struct thread_s {
    uuid_t uuid;
    char uuid_str[64];
    struct user_s *author;
    queue_t *messages;
    char name[MAX_NAME_LENGTH];
    time_t timestamp;
    struct channel_s *channel;
} thread_t;

thread_t *create_thread(void);
void delete_thread(thread_t *thread);
