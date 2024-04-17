/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** help.c
*/

#include "server_prototype.h"

void broadcast_command(server_t *server, user_t *user, packet_t *packet)
{
    char *message = packet->args[0];
    unsigned int len = strlen(user->account->name) + strlen(message) + 3;
    char *message_with_name = malloc(sizeof(char) * len);
    user_t *tmp;

    if (!message_with_name)
        return;
    sprintf(message_with_name, "%s: %s", user->account->name, message);
    for (unsigned int i = 0; i < server->users->size(server->users); i++) {
        tmp = server->users->at(server->users, i);
        if (tmp->nsock != user->nsock)
            dprintf(tmp->nsock, "%s\n", message_with_name);
    }
    free(message_with_name);
    dprintf(user->nsock, "%d Broadcast sent\n", OK);
}
