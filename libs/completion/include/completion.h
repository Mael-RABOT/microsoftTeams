/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** completion.h
*/

#pragma once

#include <termios.h>
#include <string.h>
#include "history.h"
#include "../../../include/include.h"

extern struct termios old_term;
extern char *(*completion_function)(const char *buf);

void init_completion(void);
void restore_completion(void);
void complete(char *line);
void delete_character(char *line, char *character);
