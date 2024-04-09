/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** command.h
*/

#pragma once

struct server_s;
struct user_s;

void help_command(struct server_s *server, struct user_s *user);
void login_command(struct server_s *server, struct user_s *user);
void quit_command(struct server_s *server, struct user_s *user);
