/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** completion.c
*/

#include "server.h"

static char *completion_detect_word(const char *text, int state)
{
    static int i;
    static int len;
    const char *name;

    if (state == 0) {
        i = 0;
        len = strlen(text);
    }
    while (i < MAX_COMMAND) {
        name = input_command[i].name;
        i += 1;
        if (strncmp(name, text, len) == 0) {
            return strdup(name);
        }
    }
    return NULL;
}

static char **completion(const char *text, int start, int end)
{
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, completion_detect_word);
}

void init_completion(void)
{
    rl_attempted_completion_function = completion;
}
