/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** login.c
*/

#include "prototype.h"

static account_t *find_account(queue_t *queue, char uuid[64])
{
    unsigned int i = 0;
    account_t *account = NULL;

    while (i < queue->size(queue)) {
        account = queue->at(queue, i);
        if (strcmp(account->uuid_str, uuid) == 0) {
            return account;
        }
        i += 1;
    }
    account = create_account();
    queue->push_back(queue, account);
    return account;
}

static int get_uuid(user_t *user)
{
    char **data = load_file(USER_FILE);
    char **line = NULL;

    if (!data)
        return 1;
    for (int i = 0; data[i] != NULL; i++) {
        line = split(data[i], " \n");
        if (strcmp(line[0], user->account->name) == 0) {
            uuid_parse(line[1], user->account->uuid);
            delete_array((void **)line);
            delete_array((void **)data);
            return 0;
        }
        delete_array((void **)line);
    }
    delete_array((void **)data);
    return 1;
}

void login_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->level >= LOGGED)
        return (void)dprintf(
            user->nsock, "%d Already logged in\n", BAD_REQUEST);
    if (len_array((void **)packet->args) < 1)
        return (void)dprintf(user->nsock, "%d Bad arguments\n", BAD_REQUEST);
    user->account = find_account(server->accounts, packet->args[0]);
    if (user->account == NULL) {
        user->send(user, "%d: Failed to attribute account\n");
        return;
    }
    user->level = LOGGED;
    strcpy(user->account->name, packet->args[0]);
    dprintf(user->nsock, "%d: %s: %s\n", OK, user->account->name,
        user->account->uuid_str);
}
