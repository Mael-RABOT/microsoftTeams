/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** socket.c
*/

#include "../include/socket.h"

static bool init_socket(socket_t *new_socket)
{
    new_socket->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    new_socket->addrlen = sizeof(new_socket->address);
    if (new_socket->socket_fd < 0) {
        perror("Failed to create socket");
        free(new_socket);
        return false;
    } else {
        return true;
    }
}

static void set_socket_option(socket_t *socket, int port)
{
    socket->address.sin_family = AF_INET;
    socket->address.sin_addr.s_addr = INADDR_ANY;
    socket->address.sin_port = htons(port);
}

static bool bind_socket(socket_t *socket)
{
    int res = bind(socket->socket_fd, (struct sockaddr*)&socket->address,
        sizeof(socket->address));

    if (res < 0) {
        delete_socket(socket);
        perror("Failed to bind socket");
        return false;
    } else {
        return true;
    }
}

socket_t *create_server(const int port)
{
    socket_t *socket = malloc(sizeof(socket_t));

    if (socket == NULL) {
        return NULL;
    }
    if (init_socket(socket) == false) {
        return NULL;
    }
    set_socket_option(socket, port);
    if (bind_socket(socket) == false) {
        return NULL;
    }
    return socket;
}
