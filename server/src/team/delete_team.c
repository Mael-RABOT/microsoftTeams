/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** delete_team.c
*/

#include "server_prototype.h"

void delete_team(team_t *team)
{
    if (team == NULL) {
        return;
    }
    if (team->channels != NULL) {
        team->channels->foreach(team->channels,
            (void (*)(void *))delete_channel);
        delete_queue(team->channels);
    }
    free(team);
}
