/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** init_socket.c
*/

#include "../include/socket.h"

void init_socket(socket_t *socket)
{
    if (socket == NULL) {
        return;
    }
    memset(socket, 0, sizeof(socket_t));
    socket->socket_fd = -1;
}
