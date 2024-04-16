/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** account.h
*/

#pragma once

#include <uuid/uuid.h>
#include "../../include/include.h"
#include "team.h"

struct server_s;

typedef struct account_s {
    char name[MAX_NAME_LENGTH];
    uuid_t uuid;
    char uuid_str[64];
    struct {
        team_t *team;
        channel_t *channel;
        thread_t *thread;
    } context;

} account_t;

account_t *create_account(void);
void delete_account(account_t *account);
queue_t *load_accounts(void);
