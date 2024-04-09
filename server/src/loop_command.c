/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** loop_command.c
*/

#include "server.h"

static int execute_command(server_t *server, int i)
{
    packet_t *packet = NULL;
    unsigned int read_val = 0;
    user_t *user = server->users[i];
    char command[MAX_BODY_LENGTH] = {0};

    read_val = read(user->nsock, command, 512);
    if (read_val == 0) {
        return 0;
    }
    packet = parse_command(server, command);
    delete_packet(packet);
    return 0;
}

int loop_command(server_t *server)
{
    int i = 0;

    while (server->users[i] != NULL) {
        if (FD_ISSET(server->users[i]->nsock, &server->fd_set)) {
            execute_command(server, i);
        }
        i += 1;
    }
    return 0;
}
