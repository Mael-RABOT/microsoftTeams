/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** command.c
*/

#include "../include/command.h"

struct command_s command_lists[NO_COMMAND] = {
    {HELP, 0, NOT_LOGGED},
    {LOGIN, 1, NOT_LOGGED},
    {LOGOUT, 1, LOGGED},
    {USERS, 0, NOT_LOGGED},
    {USER, 1, LOGGED},
    {SEND, 2, LOGGED},
    {MESSAGES, 1, LOGGED},
    {SUBSCRIBE, 1, LOGGED},
    {SUBSCRIBED, 1, LOGGED},
    {UNSUBSCRIBE, 1, LOGGED},
    {USE, 3, LOGGED},
    {CREATE, 2, LOGGED},
    {LIST, 0, LOGGED},
    {INFO, 0, LOGGED}
};

packet_t *create_packet(void)
{
    packet_t *packet = malloc(sizeof(packet_t));

    if (packet == NULL) {
        return NULL;
    }
    memset(packet, 0, sizeof(packet_t));
    return packet;
}

void delete_packet(packet_t *packet)
{
    if (packet == NULL) {
        return;
    }
    if (packet->args != NULL) {
        delete_array((void **)packet->args);
    }
    free(packet);
}
