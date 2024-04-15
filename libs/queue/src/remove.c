/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** remove.c
*/

#include "../include/queue.h"
#include "../include/node.h"

void remove_node(struct head_s *head, unsigned int index)
{
    node_t *node = head->at(head, index - 1);

    if (head == NULL || node == NULL || node->next == NULL) {
        return;
    }
    if (index == 0)
        head->head = head->head->next;
    else
        node->next = node->next->next;
}
