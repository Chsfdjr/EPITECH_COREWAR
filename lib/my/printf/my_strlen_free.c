/*
** EPITECH PROJECT, 2022
** my_putstr_free.c
** File description:
** my_putstr + free le str
*/

#include <stdlib.h>

int my_strlen_free(char *str)
{
    int nb = 0;
    char *copy = str;

    while (*copy != '\0') {
        copy ++;
        nb += 1;
    }
    free(str);
    return nb;
}
