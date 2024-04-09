/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** unload_server.c
*/

#include "server.h"

void unload_server(server_t *server)
{
    if (server == NULL) {
        return;
    }
    if (server->socket.socket_fd != -1) {
        close(server->socket.socket_fd);
    }
    if (server->logger != NULL) {
        delete_server_logger(server->logger);
    }
}
