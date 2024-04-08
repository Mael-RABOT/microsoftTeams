/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** completion.c
*/

#include "../include/completion.h"

struct termios old_term;
char *(*completion_function)(const char *buf);

static bool get_move(history_t *history, char *line, char character)
{
    char *hline = NULL;

    switch (character) {
        case 'A':
            hline = completion_detect_history_up(history, line);
            if (hline != NULL) {
                strcat(line, hline);
            }
            return true;
        case 'B':
            printf("DOWN\n");
            return true;
        case 'C':
            return false;
        case 'D':
            return false;
    }
    return false;
}

static bool detect_move(history_t *history, char *line, char character)
{
    if (character == '\033') {
        character = fgetc(stdin);
        if (character == '[') {
            character = fgetc(stdin);
            return get_move(history, line, character);
        }
    }
    return false;
}

static void display_line(history_t *history, char *line)
{
    int i = 0;
    int len = 0;

    printf("\r");
    while (i < len) {
        printf(" ");
        i += 1;
    }
    printf("\r%s", line);
}

static bool detect_character(char *line, char *character)
{
    if (*character == 127) {
        delete_character(line, character);
        return true;
    }
    if (*character == '\t') {
        complete(line);
        return true;
    }
    return false;
}

static void *execute_character(char *line, char *character)
{

}

static void get_input(history_t *history, char *line)
{
    char character = 0;

    while (character != EOF) {
        if (character == '\n') {
            printf("\n");
            return;
        }
        if (detect_move(history, line, character) == true) {
            display_line(history, line);
            strcat(line, history->array[history->index]);
            character = getc(stdin);
            continue;
        }
        if (detect_character(line, &character) == true) {
            continue;
        } else {
            strncat(line, &character, 1);
            display_line(history, line);
            character = fgetc(stdin);
        }
    }
}

char *my_readline(const char *prompt)
{
    char *line = malloc(1024);
    history_t *history = NULL;

    if (line == NULL) {
        return NULL;
    }
    history = load_history();
    memset(line, 0, 1024);
    get_input(history, line);
    return line;
}
