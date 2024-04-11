/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** foreach.c
*/

#include "../include/head.h"

void foreach(head_t *head, void (*func)(void *arg))
{
    unsigned int i = 0;

    while (i < head->size(head)) {
        func(head->at(head, i));
        i += 1;
    }
}
