/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** task01 day08
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len + 1; i ++)
        str[i] = src[i];
    return str;
}
