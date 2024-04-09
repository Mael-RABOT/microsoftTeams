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
            {"/help", HELP, 0, 0},
            {"/login ", LOGIN, 1, 1},
            {"/logout", LOGOUT, 0, 0},
            {"/users", USERS, 0, 0},
            {"/user ", USER, 1, 1},
            {"/send ", SEND, 2, 2},
            {"/messages ", MESSAGES, 1, 1},
            {"/subscribe ", SUBSCRIBE, 1, 1},
            {"/subscribed", SUBSCRIBED, 0, 1},
            {"/unsubscribe ", UNSUBSCRIBE, 1, 1},
            {"/use", USE, 0, 3},
            {"/create ", CREATE, 1, 2},
            {"/list", LIST, 0, 0},
            {"/info", INFO, 0, 0},
            {NULL, ERROR, 0, 0}
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

static vector_2d get_args_data(command_type_t type)
{
    for (int i = 0; get_command()[i].input != NULL; i++) {
        if (get_command()[i].command_type == type)
            return (vector_2d){
                get_command()[i].min_args, get_command()[i].max_args};
    }
    return (vector_2d){0, 0};
}

static int call_command(client_t *client, command_type_t type, char *input)
{
    vector_2d args_data = get_args_data(type);

    return normalize_command(client, type, input, args_data);
}

static int handle_input(client_t *client, char *input)
{
    command_type_t command_type;

    if (!strcmp(input, "/exit\n"))
        return 0 * client->socket.send(&client->socket, "%d", EXIT);
    if (!strcmp(input, "/help\n"))
        return 1 + 0 * printf(CHELP);
    command_type = get_command_type(input);
    switch (command_type) {
        case ERROR:
            printf("Invalid command.\n");
            return 1;
        case TEXT:
            client->socket.send(&client->socket, "%d %s", TEXT, input);
            return 1;
        default:
            if (call_command(client, command_type, input))
                printf("Invalid arguments.\n");
            return 1;
    }
}

int loop(client_t *client)
{
    int running = true;
    char *input = malloc(MAX_BODY_LENGTH * sizeof(char));

    if (input == NULL)
        return -1 + 0 * fprintf(stdin, "Failed to allocate memory.\n");
    while (running > 0) {
        memset(input, 0, MAX_BODY_LENGTH);
        write(1, "> ", 2);
        if (!fgets(input, MAX_BODY_LENGTH, stdin))
            break;
        running = handle_input(client, input);
    }
    free(input);
    return running;
}
