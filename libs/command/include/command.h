/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** command.h
*/

#pragma once

enum command_type {
    SEND
};

typedef struct command_s {
    enum command_type type;
} command_t;
