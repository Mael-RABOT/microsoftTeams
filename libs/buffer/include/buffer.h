/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** buffer.h
*/

#pragma once

#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4016

typedef struct buffer_s {
    unsigned int read_nozzle;
    unsigned int write_nozzle;
    char buffer[BUFFER_SIZE];
    void (*set_read_nozzle)(struct buffer_s *buffer, unsigned int pos);
    void (*set_write_nozzle)(struct buffer_s *buffer, unsigned int pos);
    void (*add_read_nozzle)(struct buffer_s *buffer, unsigned int pos);
    void (*add_write_nozzle)(struct buffer_s *buffer, unsigned int pos);
    void (*append)(struct buffer_s *buffer, char *string);
} buffer_t;

buffer_t *create_buffer(void);
void delete_buffer(buffer_t *buffer);
