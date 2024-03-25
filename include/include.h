/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** include.h
*/

#pragma once

#define _GNU_SOURCE

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH  255
#define MAX_BODY_LENGTH 512
#define MAX_USER    64

#include <sys/select.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdarg.h>
#include <dlfcn.h>
#include <arpa/inet.h>

#include "../libs/array/include/array.h"
#include "../libs/socket/include/socket.h"
#include "../libs/dlloader/include/dlloader.h"
#include "../libs/logging/include/logging.h"
#include "../libs/myteams/logging_client.h"
#include "../libs/myteams/logging_server.h"

char **load_file(const char *path);
void display_usage(const char *path);
int check_args(const int ac, const char **av, const int no_arg);
