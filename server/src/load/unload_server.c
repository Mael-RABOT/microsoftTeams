/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** unload_server.c
*/

#include "prototype.h"

void unload_server(server_t *server)
{
    if (server == NULL) {
        return;
    }
    if (server->socket.socket_fd != -1) {
        close(server->socket.socket_fd);
    }
    delete_server_logger(server->logger);
    server->teams->foreach(server->teams, (void (*)(void *))delete_team);
    server->users->foreach(server->users, (void (*)(void *))delete_user);
    server->accounts->foreach(server->accounts,
        (void (*)(void *))delete_account);
    delete_queue(server->teams);
    delete_queue(server->users);
    delete_queue(server->accounts);
}
