/*
** EPITECH PROJECT, 2022
** my_getfunc2.c
** File description:
** getfunc pour printf
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/proto_func.h"
#include <stdlib.h>

int get_binary(va_list list_param, char *format, int prs)
{
    unsigned int nb = va_arg(list_param, unsigned int);
    int ret = 0;
    char *binary = my_putnbr_base(nb, "01");
    if (recup_flag(format) == '#' && nb != 0)
        ret += 2;
    if (nb == 0)
        return 1;
    for (; prs > my_strlen(binary); prs --)
        ret ++;
    return ret + my_strlen_free(binary);
}

int get_hexa(va_list list_param, char *format, int prs)
{
    unsigned int nb = va_arg(list_param, unsigned int);
    int ret = 0;
    char *hexa = my_putnbr_base(nb, "0123456789abcdef");
    if (nb == 0) {
        free(hexa);
        return 1;
    }
    if (recup_flag(format) == '#')
        ret += 2;
    for (; prs > my_strlen(hexa); prs --)
        ret ++;
    return ret + my_strlen_free(hexa);;
}

int get_unsigned(va_list list_param, char *format, int prs)
{
    unsigned int nb = va_arg(list_param, unsigned int);
    char *unsign = my_putnbr_base(nb, "0123456789");
    int ret = 0;

    if (nb == 0)
        return 1;
    for (; prs > my_strlen(unsign); prs --)
        ret ++;
    return ret + my_strlen_free(unsign);
}
