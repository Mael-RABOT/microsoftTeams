/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** accept.c
*/

#include "server.h"

static void refuse_conn(server_t *server)
{
    struct sockaddr_in addr;
    socklen_t socklen = sizeof(struct sockaddr_in);
    int nsock = server->socket.accept(&server->socket,
        (struct sockaddr *)&addr, &socklen);

    dprintf(nsock, "Failed to connect user\n");
}

static void accept_conn(server_t *server)
{
    user_t *user = create_user();

    if (user == NULL) {
        refuse_conn(server);
        return;
    }
    user->socklen = sizeof(struct sockaddr_in);
    user->nsock = server->socket.accept(&server->socket,
        (struct sockaddr *)&user->addr, &user->socklen);
    append_array((void **)server->users, user);
}

int accept_conns(server_t *server)
{
    int index = len_array((void **)server->users);

    if (FD_ISSET(server->socket.socket_fd, &server->fd_set)) {
        if (index > MAX_USER) {
            refuse_conn(server);
        } else {
            accept_conn(server);
        }
    }
    return 0;
}
