/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** detect_activity.c
*/

#include "../include/buffer.h"

static bool is_found(buffer_t *buffer, unsigned int pos)
{
    unsigned int i = 0;

    while (buffer->delimiter[i] != '\0') {
        if (BUF_POS(buffer->read_nozzle + i) == BUF_POS(buffer->write_nozzle)) {
            return false;
        }
        if (buffer->buffer[pos + i] != buffer->delimiter[i]) {
            return false;
        }
        i += 1;
        i %= BUFFER_SIZE;
    }
    return true;
}

bool is_ready(buffer_t *buffer)
{
    unsigned int pos = 0;

    if (buffer == NULL) {
        return false;
    }
    pos = buffer->read_nozzle;
    while (pos != buffer->write_nozzle) {
        if (is_found(buffer, pos)) {
            return true;
        }
        pos += 1;
        pos %= BUFFER_SIZE;
    }
    return false;
}
