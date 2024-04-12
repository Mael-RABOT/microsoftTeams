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
    {HELP, NOT_LOGGED, nothing_command},
    {LOGIN, NOT_LOGGED, login_command},
    {LOGOUT, LOGGED, logout_command},
    {USERS, NOT_LOGGED, users_command},
    {USER, LOGGED, nothing_command},
    {SEND, LOGGED, send_command},
    {MESSAGES, LOGGED, message_command},
    {SUBSCRIBE, LOGGED, nothing_command},
    {SUBSCRIBED, LOGGED, nothing_command},
    {UNSUBSCRIBE, LOGGED, nothing_command},
    {USE, LOGGED, use_command},
    {CREATE, LOGGED, create_command},
    {LIST, LOGGED, nothing_command},
    {INFO, LOGGED, nothing_command},
    {EXIT, NOT_LOGGED, quit_command},
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
