/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** delete_account.c
*/

#include "server_prototype.h"

void delete_account(account_t *account)
{
    if (account == NULL) {
        return;
    }
    free(account);
}
