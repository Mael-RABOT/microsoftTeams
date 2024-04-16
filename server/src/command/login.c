/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** login.c
*/

#include "prototype.h"

static account_t *setup_account(server_t *server, packet_t *packet)
{
    account_t *account = create_account();

    if (account == NULL) {
        return NULL;
    }
    strcpy(account->name, packet->args[0]);
    server->logger->user_created(account->uuid_str, account->name);
    server->accounts->push_back(server->accounts, account);
    return account;
}

static account_t *find_account(server_t *server, user_t *user,
    packet_t *packet)
{
    unsigned int i = 0;
    account_t *account = NULL;

    while (i < server->accounts->size(server->accounts)) {
        account = server->accounts->at(server->accounts, i);
        if (strcmp(account->name, packet->args[0]) == 0) {
            return account;
        }
        i += 1;
    }
    return setup_account(server, packet);
}

void login_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->level >= LOGGED)
        return (void)dprintf(
            user->nsock, "%d Already logged in\n", BAD_REQUEST);
    if (len_array((void **)packet->args) < 1)
        return (void)dprintf(user->nsock, "%d Bad arguments\n", BAD_REQUEST);
    user->account = find_account(server, user, packet);
    if (user->account == NULL) {
        user->send(user, "%d: Failed to attribute account\n");
        return;
    }
    user->level = LOGGED;
    server->logger->user_logged_in(user->account->uuid_str);
    dprintf(user->nsock, "%d: %s: %s\n", OK, user->account->name,
        user->account->uuid_str);
}
