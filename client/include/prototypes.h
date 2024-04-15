/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** client.h
*/

#pragma once

#include "client.h"

void login_handler(client_t *client, codes_t code, char *response);
void logout_handler(client_t *client, codes_t code, char *response);
void send_handler(client_t *client, codes_t code, char *response);
void create_handler(client_t *client, codes_t code, char *response);
