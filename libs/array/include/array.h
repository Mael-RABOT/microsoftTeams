/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myftp-mathieu.borel
** File description:
** array.h
*/

#pragma once

#define _GNU_SOURCE

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void **create_array(unsigned int size);
bool delete_array(void **array);
unsigned int len_array(void **array);
bool print_array(void **array, void(*print)(const void *));
void print_str(const void *str);
void clear_array(void **array, int size);
void shift_array(void **array, int index);
void append_array(void **array, void *ptr);
void remove_array(void **array, int index);

char *array_to_str(char **array);

char **split(const char *string, const char *delim);
