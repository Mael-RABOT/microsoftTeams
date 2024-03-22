/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** server.c
*/

#include "server.h"

static int load_log_library(server_t *server)
{
    server->logger = create_server_logger("./libs/myteams/libmyteams.so");
    if (server->logger == NULL) {
        return 84;
    }
    return 0;
}

static void unload_server(server_t *server)
{
    if (server == NULL) {
        return;
    }
    if (server->logger != NULL) {
        delete_server_logger(server->logger);
    }
}

int server(const int ac, const char **av)
{
    server_t server;

    if (load_log_library(&server) == 84) {
        return 84;
    }
    if (init_server(&server.socket, 8080) == -1) {
        close(server.socket.socket_fd);
        return 84;
    }
    server.logger->channel_created("a", "b", "c");
    unload_server(&server);
    return 0;
}
