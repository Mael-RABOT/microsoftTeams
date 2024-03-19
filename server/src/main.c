/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** main.c
*/

#include "client.h"

int main(const int ac, const char **av)
{
    socket_t *socket = create_server(21);

    if (socket == NULL) {
        return 0;
    }
    return 0;
}
