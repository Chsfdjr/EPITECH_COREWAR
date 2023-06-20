/*
** EPITECH PROJECT, 2022
** my_format_func1.c
** File description:
** functions pour les formats
*/

#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/proto_func.h"
#include <stdio.h>

//renvoie la taille
int get_len_middle(char const *str, int i)
{
    char flags[] = "csdiSbxXoufFeEpagG%krvw";

    if (in_tab(flags, str[i]) == 1)
        return 1;
    return 0;
}

//taille jusqu au specifier
int get_len(char const *str, int index)
{
    int ret = 1;
    int i_f = 0;
    for (int i = index + 1; i <= my_strlen(str); i ++) {
        if (get_len_middle(str, i) == 1)
            return ret;
        if (str[i] == '\0')
            return -1;
        ret += 1;
    }
    return ret;
}

//renvoie le format du param (str)
char *recup_format(char const *str, int index)
{
    int len_f = get_len(str, index);
    char *ret = malloc(sizeof(char) * len_f + 1);
    char *copy = my_strdup(str);
    int i_copy = 0;

    for (; i_copy < index + 1; i_copy ++);
    for (int i = 0; i < len_f; i ++)
        ret[i] = copy[i_copy + i];
    ret[len_f] = '\0';
    free(copy);
    return ret;
}

int my_putformat(char const *str, int index, va_list list_param, va_list copy)
{
    char *format = recup_format(str, index);
    char *except = "krvw";

    if (in_tab(except, format[my_strlen(format) - 1]) == 1) {
        my_putchar('%');
        my_putstr(format);
        return my_strlen_free(format) + 1;
    }
    return my_putspace(format, list_param, copy);
}
