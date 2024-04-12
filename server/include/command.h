/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** command.h
*/

#pragma once

#include "../../include/command.h"

typedef struct server_s server_t;
typedef struct user_s user_t;

typedef struct command_s {
    command_type_t type;
    enum status_e required;
    void (*func)(server_t *server, user_t *user, packet_t *packet);
} command_t;

void create_command(server_t *server, user_t *user, packet_t *packet);
void use_command(server_t *server, user_t *user, packet_t *packet);
void nothing_command(server_t *server, user_t *user, packet_t *packet);
void help_command(server_t *server, user_t *user, packet_t *packet);
void login_command(server_t *server, user_t *user, packet_t *packet);
void logout_command(server_t *server, user_t *user, packet_t *packet);
void quit_command(server_t *server, user_t *user, packet_t *packet);
void send_command(server_t *server, user_t *user, packet_t *packet);
void users_command(server_t *server, user_t *user, packet_t *packet);
void message_command(server_t *server, user_t *user, packet_t *packet);
void broadcast_command(server_t *server, user_t *user, packet_t *packet);
void info_command(server_t *server, user_t *user, packet_t *packet);

extern const struct command_s command_list[];
