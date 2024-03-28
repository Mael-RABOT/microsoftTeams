/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** server.c
*/

#include "server.h"
#include <readline/readline.h>

static int launch_server(server_t *server, const char *input_port)
{
    const unsigned short port = atoi(input_port);

    if (load_server(server, port) == 84) {
        return 84;
    }
    loop(server);
    return 0;
}

int server(const int ac, const char **av)
{
    server_t server;
    int status = check_args(ac, av, 2, "./server/usage.md");

    init_completion();
    memset(&server, 0, sizeof(server_t));
    if (status != 0) {
        return (status - 1);
    }
    status = launch_server(&server, av[1]);
    unload_server(&server);
    return status;
}
