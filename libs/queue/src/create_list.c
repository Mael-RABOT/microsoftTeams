/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create_list.c
*/

#include "../include/head.h"

head_t *create_list(void)
{
    head_t *head = malloc(sizeof(head_t));

    if (head == NULL) {
        return NULL;
    }
    memset(head, 0, sizeof(head_t));
    head->push_front = &push_front;
    head->push_back = &push_back;
    head->front = &front;
    head->back = &back;
    head->at = &at;
    head->insert = &insert;
    head->size = &size;
    return head;
}
