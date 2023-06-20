/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** my_strndup
*/

#include "../include/corewar_vm.h"

char *my_strndup ( char const *src, int n)
{
    int i = 0;
    char *str = NULL;

    if (src == NULL)
        return NULL;
    if (n > my_strlen(src))
        n = my_strlen(src);
    str = malloc(sizeof(char) * (n + 1));
    for (i = 0 ;i != n && src[i] != '\0';i++)
        str[i] = src[i];
    str[n] = '\0';
    return str;
}
