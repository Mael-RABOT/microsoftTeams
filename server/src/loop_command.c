/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** loop_command.c
*/

#include "server.h"

static int parse_command(server_t *server, char *command)
{
    int type = 0;
    char line[MAX_BODY_LENGTH] = {0};
    int status = sscanf(command, "%d %s", &type, line);

    if (status == -1) {
        return 84;
    }
    printf("%d - %s\n", type, line);
    return 0;
}

static int execute_command(server_t *server, int i)
{
    unsigned int read_val = 0;
    user_t *user = server->users[i];
    char command[MAX_BODY_LENGTH] = {0};

    read_val = read(user->nsock, command, 512);
    if (read_val == 0) {
        return 0;
    }
    parse_command(server, command);
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
