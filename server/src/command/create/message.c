/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** message.c
*/

#include "server_prototype.h"

static void display_all_message(user_t *user, va_list list)
{
    message_t *message = va_arg(list, message_t *);

    user->send(user, "%d: Reply:%s:%s:%s:%s\n", CREATED,
        user->account->context.team->uuid_str,
        user->account->context.thread->uuid_str,
        user->account->uuid_str, message->content);

}

void create_server_message(server_t *server, thread_t *thread, user_t *user,
    packet_t *packet)
{
    message_t *message = create_message();
    team_t *team = thread->channel->team;

    if (len_array((void **)packet->args) < 1 || message == NULL) {
        user->send(user, "%d: Failed to create message\n", BAD_REQUEST);
        free(message);
        return;
    }
    strcpy(message->content, packet->args[0]);
    thread->messages->push_back(thread->messages, message);
    team->subscribed->foreach_arg(team->subscribed,
        (void (*)(void *, va_list))display_all_message, message);
    server_event_reply_created(thread->uuid_str, user->account->uuid_str,
        packet->args[0]);
}
