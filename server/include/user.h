/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** user.h
*/

#pragma once

#include "../../include/include.h"
#include "team.h"

typedef enum context_e {
    NO_CONTEXT,
    TEAM,
    CHANNEL,
    THREAD,
} context_t;

typedef struct user_s {
    int nsock;
    socklen_t socklen;
    enum status_e level;
    struct sockaddr_in addr;
    char name[MAX_NAME_LENGTH];
    uuid_t uuid;
    int (*send)(struct user_s *user, const char *format, ...);
    struct {
        team_t *team;
        channel_t *channel;
        thread_t *thread;
    } context;
} user_t;

user_t *create_user(void);
void delete_user(user_t *user);
context_t get_context(user_t *user);
