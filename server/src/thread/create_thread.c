/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create_thread
*/

#include "prototype.h"

thread_t *create_thread(void)
{
    thread_t *thread = malloc(sizeof(thread_t));

    if (thread == NULL) {
        return NULL;
    }
    memset(thread, 0, sizeof(thread_t));
    uuid_generate(thread->uuid);
    return thread;
}
