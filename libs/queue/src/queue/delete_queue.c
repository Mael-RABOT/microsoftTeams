/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** delete_queue.c
*/

#include "../../include/queue.h"

void delete_queue(queue_t *queue)
{
    if (queue == NULL) {
        return;
    }
    free(queue);
}
