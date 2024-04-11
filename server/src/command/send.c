/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** login.c
*/

#include "prototype.h"

void save_message(char *message, uuid_t sender_uuid, uuid_t receiver_uuid)
{
    FILE *file;
    char sender_uuid_str[37];
    char receiver_uuid_str[37];
    char filename[74 + 2];
    char line[74 + 4 + strlen(message)]

    uuid_unparse(sender_uuid, sender_uuid_str);
    uuid_unparse(receiver_uuid, receiver_uuid_str);
    sprintf(filename, "%s_%s", sender_uuid_str, receiver_uuid_str);
    file = fopen(filename, "a");
    if (file == NULL)
        return;
    sprintf(line, "%s %s %s\n", sender_uuid_str, receiver_uuid_str, message);
    fwrite(line, 1, strlen(line), file);
    fclose(file);
}

void send_command(server_t *server, user_t *user, packet_t *packet)
{
    uuid_t target_uuid;
    user_t *dest_user = NULL;

    if (uuid_parse(packet->args[0], target_uuid) == -1) {
        dprintf(user->nsock, "%d: %s\n", BAD_REQUEST, "Invalid UUID");
        return;
    }
    dest_user = get_resource(server->users, offsetof(user_t, uuid),
        target_uuid, (bool (*)(void *, void *))uuid_strict_compare);
    if (dest_user == NULL) {
        dprintf(user->nsock, "%d: %s\n", BAD_REQUEST, "User not found");
    } else {
        dprintf(dest_user->nsock, "%d: %s\n", OK, packet->args[1]);
    }
    save_message(packet->args[1], user->uuid, target_uuid);
    dprintf(user->nsock, "%d: %s\n", OK, "OK");
}
