/*
** EPITECH PROJECT, 2022
** shortcut.c
** File description:
** raccourci pour flag e et E
*/

#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include "include/proto_func.h"

int disp_scien(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);
    prs = (prs == -1) ? 6. : (double)prs;
    if (!(nb == nb)) {
        my_putstr("nan");
        return 3;
    }
    if (4.0 / nb == 0) {
        my_putstr("inf");
        return 3;
    }
    if (nb < 0. || recup_flag(format) == '+') {
        my_putchar((nb < 0) ? '-' : '+');
        nb *= (nb < 0.) ? -1. : 1.;
    }
    return disp_scienf(nb, prs, 0);
}

int disp_scien_maj(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);
    prs = (prs == -1) ? 6. : (double)prs;

    if (!(nb == nb)) {
        my_putstr("NAN");
        return 3;
    }
    if (4.0 / nb == 0) {
        my_putstr("INF");
        return 3;
    }
    if (nb < 0. || recup_flag(format) == '+') {
        my_putchar((nb < 0) ? '-' : '+');
        nb *= (nb < 0.) ? -1. : 1.;
    }
    return disp_scien_majf(nb, prs, 0);
}

int disp_inf_or_nan(double nb, int maj)
{
    if (4 / nb == 0) {
        my_putstr((maj == 0) ? "inf" : "INF");
        return 1;
    }
    if (!(nb == nb)) {
        my_putstr((maj == 0) ? "nan" : "NAN");
        return 1;
    }
    return 0;
}

int get_inf_or_nan(double nb)
{
    if (4 / nb == 0)
        return 1;
    if (!(nb == nb))
        return 1;
    return 0;
}
