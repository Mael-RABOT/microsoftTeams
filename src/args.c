/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** args.c
*/

#include "../include/include.h"

static int check_usage(const int ac, const char **av)
{
    if (ac >= 2 && strcmp(av[1], "-h") == 0) {
        display_usage("./client/usage.md");
        return 1;
    } else {
        return 0;
    }
}

int check_args(const int ac, const char **av, const int no_arg)
{
    if (check_usage(ac, av) != 0) {
        return 1;
    }
    if (ac != no_arg) {
        return 85;
    }
    return 0;
}
