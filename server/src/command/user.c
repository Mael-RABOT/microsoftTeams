/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** user.c
*/

#include "prototype.h"

static void write_team(user_t *user, user_t *user_info)
{
    char str_uuid[37];

    if (user_info->context.team == NULL)
        user->send(user, "team: no team\n");
    else {
        uuid_unparse(user_info->context.team->uuid, str_uuid);
        user->send(user, "team: %s (%s)\n",
        user_info->context.team->name, str_uuid);
    }
}

static void write_channel(user_t *user, user_t *user_info)
{
    char str_uuid[37];

    if (user_info->context.channel == NULL)
        user->send(user, "channel: no channel\n");
    else {
        uuid_unparse(user_info->context.channel->uuid, str_uuid);
        user->send(user, "channel: %s (%s)\n",
        user_info->context.channel->name, str_uuid);
    }
}

static void write_thread(user_t *user, user_t *user_info)
{
    char str_uuid[37];

    if (user_info->context.thread == NULL)
        user->send(user, "thread: no thread\n");
    else {
        uuid_unparse(user_info->context.thread->uuid, str_uuid);
        user->send(user, "thread: %s (%s)\n",
        user_info->context.thread->name, str_uuid);
    }
}

void user_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t uuid;
    user_t *user_info;

    uuid_parse(packet->args[0], uuid);
    user_info = get_resource
    (server->users, offsetof(user_t, uuid), uuid, (bool (*)
    (void *, void *))uuid_strict_compare);
    if (user_info == NULL) {
        user->send(user, "404: User not found\n");
        return;
    }
    user->send(user, "200: Here is the user information: \n");
    user->send(user, "name: %s\n", user_info->name);
    write_team(user, user_info);
    write_channel(user, user_info);
    write_thread(user, user_info);
    return;
}
