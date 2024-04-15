/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create.c
*/

#include "prototype.h"

static void create_server_team(server_t *server, user_t *user,
    packet_t *packet)
{
    team_t *team = NULL;
    char uuid_str[37];

    if (len_array((void **)packet->args) < 2) {
        user->send(user, "400 bad arguments\n");
        return;
    }
    team = create_team();
    if (team == NULL) {
        user->send(user, "400 Failed to create team\n");
        return;
    }
    uuid_unparse(team->uuid, uuid_str);
    strcpy(team->name, packet->args[0]);
    strcpy(team->desc, packet->args[1]);
    server->teams->push_back(server->teams, team);
    user->send(user, "201: Team:%s:%s:%s\n", uuid_str, team->name, team->desc);
}

static void create_server_channel(team_t *team, user_t *user, packet_t *packet)
{
    channel_t *channel = NULL;
    char uuid_str[37];

    if (len_array((void **)packet->args) < 2) {
        user->send(user, "400 Bad arguments\n");
        return;
    }
    channel = create_channel();
    if (channel == NULL) {
        user->send(user, "400 Failed to create channel\n");
        return;
    }
    strcpy(channel->name, packet->args[0]);
    strcpy(channel->desc, packet->args[1]);
    team->channels->push_back(team->channels, channel);
    uuid_unparse(channel->uuid, uuid_str);
    user->send(user, "201: Channel:%s:%s:%s\n", uuid_str, channel->name,
        channel->desc);
}

static void thread_timer(thread_t **thread, packet_t *packet, char **message)
{
    time_t now = time(NULL);

    strcpy((*thread)->name, packet->args[0]);
    strcpy((*message), packet->args[1]);
    (*thread)->timestamp = now;
}

static void create_server_thread(channel_t *channel, user_t *user,
    packet_t *packet)
{
    char *message = NULL;
    thread_t *thread = NULL;
    char t_uuid_str[37];
    char u_uuid_str[37];

    if (len_array((void **)packet->args) < 2)
        return (void)user->send(user, "400 Bad arguments\n");
    thread = create_thread();
    message = malloc(MAX_BODY_LENGTH);
    if (thread == NULL || message == NULL)
        return ((void)user->send(user, "400 Failed to create thread\n"),
        free(message), free(thread));
    thread_timer(&thread, packet, &message);
    channel->threads->push_back(channel->threads, thread);
    thread->messages->push_back(thread->messages, message);
    uuid_unparse(thread->uuid, t_uuid_str);
    uuid_unparse(user->uuid, u_uuid_str);
    user->send(user, "201: Thread:%s:%s:%ld:%s:%s\n", t_uuid_str, u_uuid_str,
        thread->timestamp, thread->name, message);
}

//TODO: Send reply to subscribers
static void create_server_message(thread_t *thread, user_t *user,
    packet_t *packet)
{
    char *message = NULL;

    if (len_array((void **)packet->args) < 1) {
        user->send(user, "400 Failed to create message\n");
    }
    message = malloc(MAX_BODY_LENGTH);
    if (message == NULL) {
        user->send(user, "400 Failed to create message\n");
        return;
    }
    strcpy(message, packet->args[0]);
    thread->messages->push_back(thread->messages, message);
    user->send(user, "201 Ok\n");
}

void create_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->context.team == NULL) {
        create_server_team(server, user, packet);
        return;
    }
    if (user->context.channel == NULL) {
        create_server_channel(user->context.team, user, packet);
        return;
    }
    if (user->context.thread == NULL) {
        create_server_thread(user->context.channel, user, packet);
        return;
    }
    create_server_message(user->context.thread, user, packet);
    return;
}
