/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** load_server.c
*/

#include "server.h"

static int load_log_library(server_t *server)
{
    server->logger = create_server_logger("./libs/myteams/libmyteams.so");
    if (server->logger == NULL) {
        return 84;
    } else {
        return 0;
    }
}

int load_server(server_t *server, const unsigned short port)
{
    memset(server, 0, sizeof(server_t));
    if (init_server(&server->socket, port) == 84) {
        close(server->socket.socket_fd);
        return 84;
    }
    if (load_log_library(server) == 84) {
        return 84;
    }
    return 0;
}
