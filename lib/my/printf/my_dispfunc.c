/*
** EPITECH PROJECT, 2022
** my_dispfunc.c
** File description:
** fonctions display pour mini_printf
*/

#include <stdarg.h>
#include "include/my.h"
#include <stdlib.h>
#include "include/proto_func.h"

int dispnb(va_list list_param, char *format, int prs)
{
    int nb = va_arg(list_param, int);
    int ret = get_diz(nb);
    char *ret_str;
    if (nb < 0 || recup_flag(format) == '+') {
        my_putchar((nb > 0) ? '+' : '-');
        nb *= (nb < 0) ? -1 : 1;
    }
    if (nb == 0)
        my_putchar('0');
    for (int i = prs; ret < i; i --)
        my_putchar('0');
    ret_str = my_putnbr_base(nb, "0123456789");
    my_putstr(ret_str);
    free(ret_str);
    return (ret > prs) ? ret : prs;
}

int dispstr(va_list list_param, char *format, int prs)
{
    char *str = va_arg(list_param, char *);
    if (prs < 0) {
        my_putstr(str);
        return my_strlen(str);
    }
    return my_putnstr(str, prs);
}

int dispchar(va_list list_param, char *format, int prs)
{
    my_putchar(va_arg(list_param, int));
    return 1;
}

void octal_zero(char *octal)
{
    int compteur = my_strlen(octal);

    for (; compteur < 3; compteur ++)
        my_putchar('0');
}

int disp_majs(va_list list_param, char *format, int prs)
{
    char *str = va_arg(list_param, char *);
    int ret = 0;
    char *octal;
    int compteur;
    for (int i = 0; i < my_strlen(str); i ++) {
        if (char_isprint(str[i]) == 0) {
            my_putchar('\\');
            octal = my_putnbr_base(str[i], "01234567");
            compteur = my_strlen(octal);
            octal_zero(octal);
            my_putstr(octal);
            ret += 4;
            free(octal);
        } else {
            my_putchar(str[i]);
            ret ++;
        }
    }
    return ret;
}
