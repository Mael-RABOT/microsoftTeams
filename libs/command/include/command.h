/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** command.h
*/

#pragma once

#include "../../../include/include.h"

enum command_type {
    A
};

typedef struct command_s {
    enum command_type type;
} command_t;
