/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** logger.c
*/

#include "server.h"

int (*client_event_logged_in)
(char const *user_uuid, const char *user_name) = NULL;

int (*client_event_logged_out)
(char const *user_uuid, const char *user_name) = NULL;

int (*client_event_private_message_received)
(char const *user_uuid, char const *message_body) = NULL;

int (*client_event_thread_reply_received)
(char const *team_uuid, char const *thread_uuid,
    char const *user_uuid, char const *reply_body) = NULL;

int (*client_event_team_created)
(char const *team_uuid, char const *team_name,
    char const *team_description) = NULL;

int (*client_event_channel_created)
(char const *channel_uuid, char const *channel_name,
    char const *channel_description) = NULL;

int (*client_event_thread_created)
(char const *thread_uuid, char const *user_uuid, time_t thread_timestamp,
    char const *thread_title, char const *thread_body) = NULL;

int (*client_print_users)
(char const *user_uuid, char const *user_name, int user_status) = NULL;

int (*client_print_teams)
(char const *team_uuid, char const *team_name,
    char const *team_description) = NULL;

int (*client_team_print_channels)
(char const *channel_uuid, char const *channel_name,
    char const *channel_description) = NULL;

int (*client_channel_print_threads)
(char const *thread_uuid, char const *user_uuid, time_t thread_timestamp,
    char const *thread_title, char const *thread_body) = NULL;

int (*client_thread_print_replies)
(char const *thread_uuid, char const *user_uuid,
    time_t reply_timestamp, char const *reply_body) = NULL;

int (*client_private_message_print_messages)
(char const *sender_uuid, time_t message_timestamp,
    char const *message_body) = NULL;

int (*client_error_unknown_team)
(char const *team_uuid) = NULL;

int (*client_error_unknown_channel)
(char const *channel_uuid) = NULL;

int (*client_error_unknown_thread)
(char const *thread_uuid) = NULL;

int (*client_error_unknown_user)
(char const *user_uuid) = NULL;

int (*client_error_unauthorized)
(char *) = NULL;

int (*client_error_already_exist)
(void) = NULL;

int (*client_print_user)
(char const *user_uuid, char const *user_name, int user_status) = NULL;

int (*client_print_team)
(char const *team_uuid, char const *team_name,
    char const *team_description) = NULL;

int (*client_print_channel)
(char const *channel_uuid, char const *channel_name,
 char const *channel_description) = NULL;

int (*client_print_thread)
(char const *thread_uuid, char const *user_uuid, time_t thread_timestamp,
    char const *thread_title, char const *thread_body) = NULL;

int (*client_print_team_created)
(char const *team_uuid, char const *team_name,
    char const *team_description) = NULL;

int (*client_print_channel_created)
(char const *channel_uuid, char const *channel_name,
    char const *channel_description) = NULL;

int (*client_print_thread_created)
(char const *thread_uuid, char const *user_uuid, time_t thread_timestamp,
    char const *thread_title, char const *thread_body) = NULL;

int (*client_print_reply_created)
(char const *thread_uuid, char const *user_uuid, time_t reply_timestamp,
    char const *reply_body) = NULL;

int (*client_print_subscribed)
(char const *user_uuid, char const *team_uuid) = NULL;

int (*client_print_unsubscribed)
(char const *user_uuid, char const *team_uuid) = NULL;

static void init_log(dlloader_t *dlloader)
{

}

dlloader_t *init_logger(const char *path)
{
    dlloader_t *dlloader = create_dlloader(path);

    if (dlloader == NULL) {
        return NULL;
    }
    return dlloader;
}
