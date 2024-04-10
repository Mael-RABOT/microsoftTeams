/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** delete_thread.c
*/

#include "thread.h"

void delete_thread(thread_t *thread)
{
    if (thread == NULL) {
        return;
    }
    free(thread);
}
