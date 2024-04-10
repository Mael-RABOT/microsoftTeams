/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** team.h
*/

#pragma once

#include "channel.h"

typedef struct team_s {
    uuid_t uuid;
    queue_t *channels;
    void (*save)(struct team_s *team);
    void (*restore)(struct team_s *team);
} team_t;

team_t *create_team(void);
void delete_team(team_t *team);
