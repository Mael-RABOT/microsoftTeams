/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** user.c
*/

#include "prototype.h"
#include <uuid/uuid.h>

static int user_send(struct user_s *user, const char *format, ...)
{
    va_list list;
    int read_val = 0;
    char *string = malloc(MAX_BODY_LENGTH);

    if (string == NULL) {
        return 0;
    }
    va_start(list, format);
    read_val = vsprintf(string, format, list);
    user->sending_buffer->append(user->sending_buffer, string);
    va_end(list);
    return read_val;
}

user_t *create_user(void)
{
    user_t *user = malloc(sizeof(user_t));

    if (user == NULL) {
        return NULL;
    }
    memset(user, 0, sizeof(user_t));
    user->send = user_send;
    return user;
}
