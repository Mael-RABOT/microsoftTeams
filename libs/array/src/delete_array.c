/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** delete_array.c
*/

#include "../include/array.h"

bool delete_array(void **array)
{
    unsigned int i = 0;

    if (array == NULL)
        return false;
    while (array[i] != NULL) {
        free(array[i]);
        i += 1;
    }
    free(array);
    return true;
}
