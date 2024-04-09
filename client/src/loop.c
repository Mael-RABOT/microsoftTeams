/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** loop.c
*/

#include "client.h"

static command_map *get_command(void)
{
    static command_map map[] = {
            {"/help", HELP},
            {"/login", LOGIN},
            {"/logout", LOGOUT},
            {"/users", USERS},
            {"/user", USER},
            {"/send", SEND},
            {"/messages", MESSAGES},
            {"/subscribe", SUBSCRIBE},
            {"/subscribed", SUBSCRIBED},
            {"/unsubscribe", UNSUBSCRIBE},
            {"/use", USE},
            {"/create", CREATE},
            {"/list", LIST},
            {"/info", INFO},
            {NULL, ERROR}
    };

    return map;
}

static command_type_t get_command_type(char *input)
{
    command_map *map = get_command();

    for (int i = 0; map[i].input != NULL; i++) {
        if (strstr(input, map[i].input) != NULL)
            return (map[i].command_type);
    }
    if (input[0] == '/')
        return ERROR;
    return TEXT;
}

static int handle_input(client_t *client, char *input)
{
    command_type_t command_type;

    if (!strcmp(input, "/exit\n"))
        return 0;
    command_type = get_command_type(input);
    switch (command_type) {
        case ERROR:
            printf("Invalid command.\n");
            return 1;
        case TEXT:
            client->socket.send(&client->socket, "%d %s", TEXT, input);
            return 1;
        default:
            if (normalize_command(client, command_type, input))
                printf("Invalid arguments.\n");
            return 1;
    }
}

int loop(client_t *client)
{
    int running = true;
    char *input = malloc(256 * sizeof(char));

    if (input == NULL)
        return -1 + 0 * fprintf(stdin, "Failed to allocate memory.\n");
    while (running > 0) {
        memset(input, 0, 256);
        write(1, "> ", 2);
        fgets(input, 256, stdin);
        running = handle_input(client, input);
    }
    free(input);
    return running;
}
