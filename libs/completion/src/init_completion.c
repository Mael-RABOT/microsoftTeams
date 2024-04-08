/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** init_completion.c
*/

#include "../include/completion.h"

void init_completion(void)
{
    struct termios new_term;

    tcgetattr(0, &old_term);
    new_term.c_lflag &= ~(ICANON | ECHO);
    memmove(&old_term, &new_term, sizeof(struct termios));
    tcsetattr(0, TCSANOW, &new_term);
}
