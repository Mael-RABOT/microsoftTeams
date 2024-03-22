/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** main.c
*/

#include "server.h"

void debug(void)
{
    pid_t pid = getpid();

    printf("PID: %d\n", pid);
}

int main(const int ac, const char **av)
{
    return server(ac, av);
}
