/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** delete_socket.c
*/

#include "../include/socket.h"

void delete_socket(socket_t *socket)
{
    if (socket == NULL) {
        return;
    }
    close(socket->socket_fd);
    free(socket);
}
