/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** users.c
*/

#include "server.h"

void users_command(server_t *server, user_t *user, packet_t *packet)
{
    char **users = load_file(USER_FILE);

    if (!users)
        return;
    user->send(user, "200: Here is the list of users :\n");
    for (int i = 0; users[i] != NULL; i++)
        user->send(user, users[i]);
    delete_array((void **)users);
    return;
}
