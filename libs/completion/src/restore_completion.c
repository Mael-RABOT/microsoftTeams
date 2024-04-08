/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** restore_completion.c
*/

#include "../include/completion.h"

void restore_completion(void)
{
    tcsetattr(0, TCSANOW, &old_term);
}
