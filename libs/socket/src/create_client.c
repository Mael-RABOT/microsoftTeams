/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create_client.c
*/

#include "../include/socket.h"

static bool init_socket(socket_t *new_socket)
{
    new_socket->socket_fd = socket(AF_INET, SOCK_STREAM, 6);
    new_socket->addrlen = sizeof(new_socket->address);
    if (new_socket->socket_fd < 0) {
        perror("Socket failed");
        free(new_socket);
        return false;
    } else {
        return true;
    }
}

static void set_socket_option(socket_t *socket, const int address,
    const int port)
{
    socket->address.sin_addr.s_addr = address;
    socket->address.sin_family = AF_INET;
    socket->address.sin_port = htons(port);
}

socket_t *create_client(const int address, const int port)
{
    socket_t *socket = malloc(sizeof(socket_t));

    if (socket == NULL) {
        return NULL;
    }
    if (init_socket(socket) == false) {
        return NULL;
    }
    set_socket_option(socket, address, port);
    return socket;
}
