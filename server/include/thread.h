/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** thread.h
*/

#pragma once

#include "../../include/include.h"

typedef struct thread_s {
    uuid_t uuid;
    void (*save)(struct thread_s *thread);
    void (*restore)(struct thread_s *thread);
} thread_t;

thread_t *create_thread(void);
void delete_thread(thread_t *thread);
