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
    return TEXT;
}

static void normalize_command(
    client_t *client, command_type_t command_type, char *input)
{
    char **array = split(input, " ");
    int length;
    char *new_str;

    for (length = 0; array[length + 1] != NULL; length++);
    new_str = malloc((length * 256) * sizeof(char));
    if (new_str == NULL)
        return (void)printf("Failed to allocate memory.\n");
    new_str[0] = '\0';
    for (int i = 1; i <= length; i++) {
        strcat(new_str, "\"");
        strcat(new_str, array[i]);
        strcat(new_str, "\" ");
    }
    new_str[strlen(new_str) - 1] = '\0';
    client->socket.send(&client->socket, "%d %s", command_type, new_str);
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
            return -1;
        case TEXT:
            client->socket.send(&client->socket, "%d %s", TEXT, input);
            return 1;
        default:
            normalize_command(client, command_type, input);
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
