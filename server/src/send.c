/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** send.c
*/

#include "server_prototype.h"

static void send_user_buffer(user_t *user)
{
    unsigned int read_size = 0;
    unsigned int pos = user->sending_buffer->read_nozzle;
    unsigned int to_write = BUFFER_SIZE - pos;

    read_size = write(user->nsock, &user->sending_buffer->buffer[pos],
        to_write);
    user->sending_buffer->add_read_nozzle(user->sending_buffer, read_size);
}

void send_buffer(server_t *server)
{
    unsigned int i = 0;
    user_t *user = NULL;

    while (i < server->users->size(server->users)) {
        user = server->users->at(server->users, i);
        if (FD_ISSET(user->nsock, &server->write_fds)) {
            send_user_buffer(user);
        }
        i += 1;
    }
}
