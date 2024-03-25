/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** main.c
*/

#include "server.h"

const input_command_t input_command[] = {
    {"exit", display}
};

void debug(void)
{
    pid_t pid = getpid();

    printf("PID: %d\n", pid);
}

int main(const int ac, const char **av)
{
    return server(ac, av);
}
