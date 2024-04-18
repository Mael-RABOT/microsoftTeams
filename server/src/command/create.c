/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create.c
*/

#include "server_prototype.h"

static void create_server_team(server_t *server, user_t *user,
    packet_t *packet)
{
    team_t *team = NULL;

    if (len_array((void **)packet->args) < 2) {
        user->send(user, "%d: bad arguments\n", BAD_REQUEST);
        return;
    }
    team = create_team();
    if (team == NULL) {
        user->send(user, "%d: Failed to create team\n", INTERNAL_ERROR);
        return;
    }
    strcpy(team->name, packet->args[0]);
    strcpy(team->desc, packet->args[1]);
    server->teams->push_back(server->teams, team);
    user->send(user, "%d: Team:%s:%s:%s\n", CREATED, team->uuid_str,
        team->name, team->desc);
    server_event_team_created(team->uuid_str, team->name,
        user->account->uuid_str);
}

static void create_server_channel(server_t *server, team_t *team, user_t *user,
    packet_t *packet)
{
    channel_t *channel = NULL;

    if (len_array((void **)packet->args) < 2) {
        user->send(user, "%d: bad arguments\n", BAD_REQUEST);
        return;
    }
    channel = create_channel();
    if (channel == NULL) {
        user->send(user, "%d: failed to create channel\n", BAD_REQUEST);
        return;
    }
    strcpy(channel->name, packet->args[0]);
    strcpy(channel->desc, packet->args[1]);
    team->channels->push_back(team->channels, channel);
    server_event_channel_created(team->uuid_str, channel->uuid_str,
        channel->name);
    user->send(user, "%d: Channel:%s:%s:%s\n", CREATED, channel->uuid_str,
        channel->name, channel->desc);
}

static void thread_timer(thread_t **thread, packet_t *packet, char **message)
{
    time_t now = time(NULL);

    strcpy((*thread)->name, packet->args[0]);
    strcpy((*message), packet->args[1]);
    (*thread)->timestamp = now;
}

static void create_server_thread(server_t *server, channel_t *channel,
    user_t *user, packet_t *packet)
{
    char *message = malloc(MAX_BODY_LENGTH);
    thread_t *thread = create_thread();

    if (len_array((void **)packet->args) < 2 || message == NULL
            || thread == NULL) {
        user->send(user, "%d: Failed to create thread\n", BAD_REQUEST);
        free_n(2, message, thread);
        return;
    }
    thread_timer(&thread, packet, &message);
    channel->threads->push_back(channel->threads, thread);
    thread->messages->push_back(thread->messages, message);
    user->send(user, "%d: Thread:%s:%s:%ld:%s:%s\n", CREATED, thread->uuid_str,
        user->account->uuid_str, thread->timestamp, thread->name, message);
    server_event_thread_created(channel->uuid_str, thread->uuid_str,
        user->account->uuid_str, thread->name, packet->args[1]);
}

static void create_server_message(server_t *server, thread_t *thread,
    user_t *user, packet_t *packet)
{
    char *message = malloc(MAX_BODY_LENGTH);

    if (len_array((void **)packet->args) < 1 || message == NULL) {
        user->send(user, "%d: Failed to create message\n", BAD_REQUEST);
        free(message);
        return;
    }
    strcpy(message, packet->args[0]);
    thread->messages->push_back(thread->messages, message);
    user->send(user, "%d: Reply:%s:%s:%s:%s\n", CREATED,
        user->account->context.team->uuid_str,
        user->account->context.thread->uuid_str,
        user->account->uuid_str,
        packet->args[0]);
    server_event_reply_created(thread->uuid_str, user->account->uuid_str,
        packet->args[0]);
}

void create_command(server_t *server, user_t *user, packet_t *packet)
{
    if (user->account->context.team == NULL) {
        create_server_team(server, user, packet);
        return;
    }
    if (user->account->context.channel == NULL) {
        create_server_channel(server, user->account->context.team, user,
            packet);
        return;
    }
    if (user->account->context.thread == NULL) {
        create_server_thread(server, user->account->context.channel, user,
            packet);
        return;
    }
    create_server_message(server, user->account->context.thread, user, packet);
    return;
}
