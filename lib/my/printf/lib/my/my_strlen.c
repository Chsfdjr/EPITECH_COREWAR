/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** task03
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int nb = 0;

    while (str[nb] != '\0')
        nb ++;
    return (nb);
}
