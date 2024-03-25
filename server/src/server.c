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
    unsigned short port;
    int status = args(ac, av);

    if (status != 0) {
        return (status - 1);
    }
    port = atoi(av[1]);
    load_server(&server, port);
    if (server.socket.listen(&server.socket, port) == -1) {
        return 84;
    }
    loop(&server);
    unload_server(&server);
    return 0;
}
