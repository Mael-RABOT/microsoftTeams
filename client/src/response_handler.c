/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** loop.c
*/

#include "client.h"

static void handle_code(client_t *client, command_type_t type, codes_t code)
{
    if (code >= OK && code < BAD_REQUEST)
        return (void)write(2, "LOGGER: OK.\n", 12);
    if (code >= BAD_REQUEST && code < INTERNAL_ERROR)
        return (void)write(2, "LOGGER: Bad request.\n", 21);
    if (code >= INTERNAL_ERROR)
        return (void)write(2, "LOGGER: Internal error.\n", 24);
}

int response_handler(client_t *client, command_type_t type)
{
    char *response = client->socket.recv(&client->socket);
    int code;

    (void)code;
    if (response == NULL)
        return 1;
    code = atoi(response);
    write(1, response, strlen(response));
    free(response);
    return 0;
}
