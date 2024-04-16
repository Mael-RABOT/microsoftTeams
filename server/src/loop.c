/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** loop.c
*/

#include "prototype.h"

int reset_fd_set(server_t *server)
{
    unsigned int i = 0;
    int tmp_fd = 0;
    struct timeval timeval = {0};
    int last_fd = server->socket.socket_fd;

    FD_ZERO(&server->fd_set);
    FD_SET(0, &server->fd_set);
    FD_SET(server->socket.socket_fd, &server->fd_set);
    while (i < server->users->size(server->users)) {
        tmp_fd = ((user_t *)server->users->at(server->users, i))->nsock;
        FD_SET(tmp_fd, &server->fd_set);
        last_fd = (last_fd > tmp_fd) ? last_fd : tmp_fd;
        i += 1;
    }
    select(last_fd + 1, &server->fd_set, NULL, NULL, &timeval);
    return 0;
}

int loop(server_t *server)
{
    int running = 1;

    while (running) {
        reset_fd_set(server);
        accept_conns(server);
        loop_command(server);
        disconnect(server);
        if (FD_ISSET(0, &server->fd_set)) {
            read_stdin(server, &running);
        }
    }
    return 0;
}
