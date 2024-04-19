/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** thread.c
*/

#include "server_prototype.h"

static void thread_timer(thread_t *thread, packet_t *packet,
    message_t *message)
{
    time_t now = time(NULL);

    strcpy(thread->name, packet->args[0]);
    strcpy(message->content, packet->args[1]);
    thread->timestamp = now;
}

static void display_all_thread(user_t *user, va_list list)
{
    thread_t *thread = va_arg(list, thread_t *);
    message_t *message = va_arg(list, message_t *);

    user->send(user, "%d: Thread:%s:%s:%ld:%s:%s\n", CREATED, thread->uuid_str,
        user->account->uuid_str, thread->timestamp, thread->name,
        message->content);
}

void create_server_thread(server_t *server, channel_t *channel, user_t *user,
    packet_t *packet)
{
    message_t *message = create_message();
    thread_t *thread = create_thread();

    if (len_array((void **)packet->args) < 2 || message == NULL
            || thread == NULL) {
        user->send(user, "%d: Failed to create thread\n", BAD_REQUEST);
        free_n(2, message, thread);
        return;
    }
    thread->channel = channel;
    thread_timer(thread, packet, message);
    channel->threads->push_back(channel->threads, thread);
    thread->messages->push_back(thread->messages, message);
    channel->team->subscribed->foreach_arg(channel->team->subscribed,
        (void (*)(void *, va_list))display_all_thread, thread, message);
    server_event_thread_created(channel->uuid_str, thread->uuid_str,
        user->account->uuid_str, thread->name, packet->args[1]);
}
