/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** server.c
*/

#include "server.h"

int server(const int ac, const char **av)
{
    server_t server;
    logger_t *logger = create_logger("./libs/myteams/libmyteams.so");

    if (logger == NULL) {
        return 84;
    }
    if (init_server(&server.socket, 8080) == -1) {
        close(server.socket.socket_fd);
        return 84;
    }
    logger->team_created("a", "b", "c");
    delete_logger(logger);
    return 0;
}
