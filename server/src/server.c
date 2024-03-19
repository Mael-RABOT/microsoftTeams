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

    memset(&server, 0, sizeof(server_t));
    if (init_server(&server.socket, 21) == -1) {
        close(server.socket.socket_fd);
        return 84;
    }
    return 0;
}
