/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** load_account.c
*/

#include "prototype.h"

static account_t* load_account(const char *line)
{
    char **array = split(line, " ");
    account_t *account = create_account();

    if (array == NULL || account == NULL) {
        delete_array((void **)array);
        delete_account(account);
        return NULL;
    }
    strcpy(account->name, array[0]);
    strcpy(account->uuid_str, array[1]);
    uuid_parse(account->uuid_str, account->uuid);
    delete_array((void **)array);
    return account;
}

static void parse_account_array(char **array, account_t **accounts)
{
    int i = 0;
    account_t *account = NULL;

    while (array[i] != NULL) {
        account = load_account(array[i]);
        if (account != NULL) {
            accounts[i] = account;
        }
        i += 1;
    }
}

account_t **load_accounts(server_t *server)
{
    char **array = (char **)load_file("./data/users.txt");
    account_t **accounts = (account_t **)create_array(len_array((void **)array) + 1);

    if (array == NULL || accounts == NULL) {
        delete_array((void **)array);
    }
    parse_account_array(array, accounts);
    delete_array((void **)array);
    return accounts;
}
