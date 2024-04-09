/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** main.c
*/

#include "server.h"

#ifdef COMPLETION
const bool completion = true;
#else
const bool completion = false;
#endif

const input_command_t input_command[MAX_COMMAND] = {
    {"exit", display},
    {"clear", clear},
    {"display", display}
};

void handler(int signum)
{
    restore_term();
    _exit(139);
}

void debug(void)
{
    pid_t pid = getpid();

    printf("PID: %d\n", pid);
}

int main(const int ac, const char **av, const char **env)
{
    debug();
    signal(11, handler);
    return server(ac, av, env);
}
