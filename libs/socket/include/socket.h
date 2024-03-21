/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** socket.h
*/

#pragma once

#include "../../../include/include.h"
#include <netinet/in.h>

typedef struct socket_s {
    int socket_fd;
    struct sockaddr_in address;
    socklen_t addrlen;
    void (*send)(struct socket_s *socket, const char *format, ...);
} socket_t;

socket_t *create_server(const int port);
int init_server(socket_t *socket, const int port);
socket_t *create_client(const int address, const int port);
int init_client(socket_t *socket, const int address, const int port);
void delete_socket(socket_t *socket);
void init_socket(socket_t *socket);
