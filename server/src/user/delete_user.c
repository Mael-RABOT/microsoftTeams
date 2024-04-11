/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** delete_user.c
*/

#include "prototype.h"

void delete_user(user_t *user)
{
    if (user == NULL) {
        return;
    }
    if (user->nsock != -1)
        close(user->nsock);
    free(user);
}
