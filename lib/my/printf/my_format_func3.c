/*
** EPITECH PROJECT, 2022
** my_format_func3
** File description:
** format func part 3
*/

#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/proto_func.h"
#include <stdio.h>

int size_tab(char *str)
{
    int x = 0, y = 1;
    for (;x < my_strlen(str) && y == 1;x++)
        if (str[x] == '.')
            y = 42;
    if (y == 42) {
        x++;
        for (y = 0; x < my_strlen(str)
        && ((str[x] >= '0') && (str[x] <= '9')); x++)
            y++;
    }
    return y;
}

int precision (char* format, va_list list_param, va_list copy)
{
    int i = 0;
    int a = 0;
    char temp[size_tab(format) + 1];
    temp[0] = '0';
    temp[1] = '\0';
    if (in_tab(format,'.') == 0)
        return -1;
    while (format[i] != '\0') {
        for (;format[i] != '.';i++);
        i++;
        a = i;
        if (format[i] == '*')
            return (va_arg(list_param, int) * 2) - va_arg(copy ,int);
        for (;format[i] >= '0' && format[i] <= '9'; i++)
            temp[i - a] = format[i];
        temp[i - a + 1] = '\0';
        for (;format[i] != '\0';i++);
    }
    a = my_getnbr(temp);
    return (a);
}
