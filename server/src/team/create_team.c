/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create_team.c
*/

#include "team.h"

team_t *create_team(void)
{
    team_t *team = malloc(sizeof(team_t));

    if (team == NULL) {
        return NULL;
    }
    memset(team, 0, sizeof(team_t));
    team->channels = NEW(queue);
    if (team->channels == NULL) {
        free(team);
        return NULL;
    }
    uuid_generate(team->uuid);
    return team;
}
