/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** args.c
*/

#include "server.h"

static int check_usage(const int ac, const char **av)
{
    if (ac >= 2 && strcmp(av[1], "-h") == 0) {
        display_usage("./server/usage.md");
        return 1;
    } else {
        return 0;
    }
}

static bool is_number(const char *port)
{
    int i = 0;

    while (port[i] != '\0') {
        if (port[i] < 48 || port[i] > 57) {
            return false;
        }
        i += 1;
    }
    return true;
}

int args(const int ac, const char **av)
{
    if (check_usage(ac, av) != 0) {
        return 1;
    }
    if (ac != 2) {
        return 85;
    }
    if (is_number(av[1]) == false) {
        return 85;
    }
    return 0;
}
