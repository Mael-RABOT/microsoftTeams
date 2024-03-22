/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** user.h
*/

#pragma once

#include "../../include/include.h"

typedef struct user_s {
    int nsock;
    struct sockaddr_in addr;
    socklen_t socklen;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int (*send)(struct user_s *user, const char *format, ...);
} user_t;

user_t *create_user(void);
void delete_user(user_t *user);
