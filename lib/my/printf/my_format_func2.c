/*
** EPITECH PROJECT, 2022
** my_format_func2.c
** File description:
** formating du printf
*/

#include <stdarg.h>
#include "include/proto_func.h"
#include "include/my.h"
#include <stdlib.h>

int my_putspace(char *format, va_list list_param, va_list copy)
{
    char specifier = format[my_strlen(format) - 1];
    int width = recup_width(format, list_param, copy);
    int prs = precision(format, list_param, copy);
    int size_arg = my_get_param(specifier, copy, format, prs);
    char flag = recup_flag(format);
    if (flag == '-') {
        my_put_param(specifier, list_param, format, prs);
        free(format);
        for (int i = 0; i < width - size_arg; i ++)
            my_putchar(' ');
        return (width < size_arg) ? size_arg : width;
    }
    for (int i = 0; i < width - size_arg; i ++)
        my_putchar((flag == '0') ? '0' : ' ');
    my_put_param(specifier, list_param, format, prs);
    free(format);
    return (width < size_arg) ? size_arg : width;
}

int in_tab(char *str, char c)
{
    for (int i = 0; i < my_strlen(str); i ++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

char recup_flag(char *format)
{
    char *flag = "+-#0";
    if (in_tab(flag, format[0]) == 1)
        return format[0];
    return ' ';
}

int recup_width(char *format, va_list list_param, va_list copy)
{
    int i = 0;
    int ret = 0;
    char specifier[] = "csdiSbxXoufFeEpagGA%.";
    while (!(format[i] <= '9' && format[i] >= '1')
        && format[i] != '*' && format[i] != '.') {
        if (in_tab(specifier, format[i]))
            return 0;
        i ++;
    }
    if (format[i] == '*') {
        ret = va_arg(copy, int);
        return va_arg(list_param, int);
    }
    while (format[i] <= '9' && format[i] >= '0') {
        ret *= 10;
        ret += format[i] - 48;
        i ++;
    }
    return ret;
}

int recup_prs(char *format, va_list list_param, va_list copy)
{
    int i = 0;
    int ret = 0;
    for (; format[i] != '.' || i < my_strlen(format); i++);
    if (i == my_strlen(format))
        return -1;
    i ++;
    if (format[i] == '*') {
        ret = va_arg(copy, int);
        return va_arg(list_param, int);
    }
    while (format[i] <= '9' && format[i] >= '0') {
        ret *= 10;
        ret += format[i] - 48;
        i ++;
    }
    return ret;
}
