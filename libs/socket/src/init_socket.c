/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** init_socket.c
*/

#include "../include/socket.h"

static int socket_accept(struct socket_s *socket, struct sockaddr *addr,
    socklen_t *len)
{
    return accept(socket->socket_fd, addr, len);
}

static int socket_listen(struct socket_s *socket, int backlog)
{
    return listen(socket->socket_fd, backlog);
}

static int socket_send(struct socket_s *socket, const char *format, ...)
{
    va_list list;
    int read_val = 0;

    va_start(list, format);
    read_val = dprintf(socket->socket_fd, format, list);
    va_end(list);
    return read_val;
}

static int socket_connect(struct socket_s *socket)
{
    return connect(socket->socket_fd, (struct sockaddr *)&socket->address,
        socket->addrlen);
}

void init_socket(socket_t *socket)
{
    if (socket == NULL) {
        return;
    }
    memset(socket, 0, sizeof(socket_t));
    socket->socket_fd = -1;
    socket->send = socket_send;
    socket->listen = socket_listen;
    socket->accept = socket_accept;
    socket->connect = socket_connect;
}
