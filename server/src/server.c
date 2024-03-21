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
    void **array = create_array(2);

    logger_t *logger = create_logger("libs/myteams/libmyteams.so");
    logger->channel_created("a", "b", "c");
    memset(&server, 0, sizeof(server_t));
    if (init_server(&server.socket, 8080) == -1) {
        close(server.socket.socket_fd);
        return 84;
    }
    delete_array(array);
    return 0;
}
