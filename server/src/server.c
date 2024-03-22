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

    load_server(&server, 8080);
    server.socket.listen(&server.socket, 10);
    loop(&server);
    unload_server(&server);
    return 0;
}
