/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** loop.c
*/

#include "client.h"

static int get_length(char **array)
{
    int length;

    for (length = 0; array[length + 1] != NULL; length++);
    return length;
}

static char *allocate_and_fill_new_str(char **array, int length)
{
    char *new_str = calloc((length * MAX_BODY_LENGTH), sizeof(char));
    char *end = new_str;

    if (new_str != NULL) {
        for (int i = 1; i <= length; i++)
            end += sprintf(end, "%s ", array[i]);
    }
    return new_str;
}

static int check_quotes(char **array, int length, char *new_str)
{
    for (int i = 1; i <= length; i++)
        if (array[i][0] != '\"' || array[i][strlen(array[i])-1] != '\"') {
            free(new_str);
            return 1;
        }
    return 0;
}

static void trim_trailing_spaces_and_newlines(char *new_str)
{
    while (new_str[strlen(new_str) - 1] == ' '
        || new_str[strlen(new_str) - 1] == '\n')
        new_str[strlen(new_str) - 1] = '\0';
}

int normalize_command(
    client_t *client, command_type_t command_type, char *input)
{
    char **array = split(input, " ");
    int length = get_length(array);
    char *new_str;

    if (array[length][strlen(array[length]) - 1] == '\n')
        array[length][strlen(array[length]) - 1] = '\0';
    new_str = allocate_and_fill_new_str(array, length);
    if (new_str == NULL) {
        printf("Failed to allocate memory.\n");
        return 0 * (int)delete_array((void **)array);
    }
    if (check_quotes(array, length, new_str)) {
        delete_array((void **)array);
        return 1;
    }
    trim_trailing_spaces_and_newlines(new_str);
    client->socket.send(&client->socket, "%d %s", command_type, new_str);
    free(new_str);
    delete_array((void **)array);
    return 0;
}
