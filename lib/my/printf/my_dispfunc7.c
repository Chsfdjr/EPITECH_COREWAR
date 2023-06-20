/*
** EPITECH PROJECT, 2022
** my_dispfunc7.c
** File description:
** flag %
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/proto_func.h"

int disp_percent(va_list list_param, char *format, int prs)
{
    my_putchar('%');;
    return 1;
}

int flagg_neg(double nb, char *format)
{
    if (nb < 0. || recup_flag(format) == '+')
        my_putchar((nb < 0.) ? '-' : '+');
    return (nb < 0.) ? -1. : 1.;
}

int get_flagg_neg(double nb)
{
    return (nb < 0.) ? -1. : 1.;
}
