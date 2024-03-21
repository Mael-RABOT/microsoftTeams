/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** init_socket.c
*/

#include "../include/socket.h"

static void socket_send(struct socket_s *socket, const char *format, ...)
{
    va_list list;

    va_start(list, format);
    dprintf(socket->socket_fd, format, list);
    va_end(list);
}

void init_socket(socket_t *socket)
{
    if (socket == NULL) {
        return;
    }
    memset(socket, 0, sizeof(socket_t));
    socket->socket_fd = -1;
    socket->send = socket_send;
}
