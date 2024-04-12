/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** get_context
*/

#include "prototype.h"

context_t get_context(user_t *user)
{
    if (user->context.team == NULL) {
        return NO_CONTEXT;
    }
    if (user->context.channel == NULL) {
        return TEAM;
    }
    if (user->context.thread == NULL) {
        return CHANNEL;
    }
    return THREAD;
}
