/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** loop.c
*/

#include "client_prototype.h"

static response_handler_t handlers[] = {
    {LOGIN, login_handler},
    {LOGOUT, logout_handler},
    {USERS, NULL},
    {USER, NULL},
    {SEND, NULL},
    {MESSAGES, NULL},
    {SUBSCRIBED, NULL},
    {SUBSCRIBE, NULL},
    {UNSUBSCRIBE, NULL},
    {USE, NULL},
    {CREATE, create_handler},
    {LIST, NULL},
    {INFO, NULL},
    {END, NULL}
};

static int nbr_len(int n)
{
    if (n < 10)
        return 1;
    return 1 + nbr_len(n / 10);
}

static void remove_trailing_newline(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

static int special_case(client_t *client, int code, char *data)
{
    if (code == MESSAGE_RECEIVED)
        return (send_handler(client, code, data), 1);
    if (code == CREATED)
        return (create_handler(client, code, data), 1);
    return 0;
}

static void handler(
    client_t *client, command_type_t type, int code, char *data)
{
    if (special_case(client, code, data))
        return;
    for (int i = 0; handlers[i].type != END; i++)
        if (handlers[i].type == type && handlers[i].handler)
            return handlers[i].handler(client, code, data);
}

int response_handler(client_t *client, command_type_t type)
{
    char *response = client->socket.recv(&client->socket);
    char *data = NULL;
    int code;
    int len;

    if (response == NULL)
        return 1;
    remove_trailing_newline(response);
    code = atoi(response);
    len = nbr_len(code);
    data = response + (len + 2);
    handler(client, type, code, data);
    write(1, response, strlen(response));
    write(1, "\n", 1);
    return (free(response), 0);
}
