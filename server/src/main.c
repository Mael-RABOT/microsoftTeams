/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** main.c
*/

#include "channel.h"
#include "prototype.h"

#ifdef COMPLETION
const bool completion = true;
#else
const bool completion = false;
#endif

const input_command_t input_command_list[NO_INPUT_COMMAND] = {
    {"exit", display},
    {"clear", clear},
    {"display", display}
};

const struct command_s command_list[] = {
    {HELP, 0, NOT_LOGGED, nothing_command},
    {LOGIN, 1, NOT_LOGGED, login_command},
    {LOGOUT, 1, LOGGED, logout_command},
    {USERS, 0, NOT_LOGGED, users_command},
    {USER, 1, LOGGED, nothing_command},
    {SEND, 2, LOGGED, send_command},
    {MESSAGES, 1, LOGGED, nothing_command},
    {SUBSCRIBE, 1, LOGGED, nothing_command},
    {SUBSCRIBED, 1, LOGGED, nothing_command},
    {UNSUBSCRIBE, 1, LOGGED, nothing_command},
    {USE, 3, LOGGED, nothing_command},
    {CREATE, 2, LOGGED, create_command},
    {LIST, 0, LOGGED, nothing_command},
    {INFO, 0, LOGGED, nothing_command},
    {EXIT, 0, NOT_LOGGED, quit_command},
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
