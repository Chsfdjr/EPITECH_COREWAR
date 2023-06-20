/*
** EPITECH PROJECT, 2022
** my_putnstr.c
** File description:
** fonctions pr print les n premiers char
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putnstr(char const *str, int nb)
{
    int len = (nb < my_strlen(str)) ? nb : my_strlen(str);

    write(1, str, len);
    return len;
}
