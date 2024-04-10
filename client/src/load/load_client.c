/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** load_client.c
*/

#include "client.h"

static int load_log_library(client_t *client)
{
    client->logger = create_client_logger("./libs/myteams/libmyteams.so");
    if (client->logger == NULL) {
        return 84;
    } else {
        return 0;
    }
}

int load_client(client_t *client, const unsigned int address,
    const unsigned short port)
{
    memset(client, 0, sizeof(client_t));
    if (init_client(&client->socket, address, port) == 84) {
        close(client->socket.socket_fd);
        return 84;
    }
    if (load_log_library(client) == 84) {
        return 84;
    }
    if (client->socket.connect(&client->socket) == -1) {
        return 84;
    }
    printf("%s", client->socket.recv(&client->socket));
    return 0;
}
