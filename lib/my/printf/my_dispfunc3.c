/*
** EPITECH PROJECT, 2022
** my_dispfunc3.c
** File description:
** fonctions display pour printf 3
*/

#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include "include/proto_func.h"
#include <stdlib.h>

int disp_octal(va_list list_param, char *format, int prs)
{
    unsigned int nb = va_arg(list_param, unsigned int);
    char *octal = my_putnbr_base(nb, "01234567");
    int ret = 0;
    if (nb == 0) {
        my_putchar('0');
        free(octal);
        return 1;
    }
    if (recup_flag(format) == '#') {
        my_putchar('0');
        ret += 1;
        prs --;
    }
    for (; prs > my_strlen(octal); prs --)
        my_putchar('0');
    my_putstr(octal);
    return ret + my_strlen_free(octal);
}

void exponent(int e)
{
    int ret;
    if (e < 10) {
        my_putchar('0');
        my_put_nbr(e);
    } else
        my_put_nbr(e);
}

int affichage00(double prs, char *signe)
{
    my_putstr("0.");
    for (int t = 0; t != prs; t++)
        my_putchar('0');
    my_putstr(signe);
    my_putstr("00");
    return 6 + prs;
}

int disp_scienf(double nb, double prs, int put_zero)
{
    int e = 0;
    int ret = 0;
    if (nb == 0.0)
        return affichage00(prs,"e+");
    if (nb >= 1) {
        for (e = 0; nb >= 10; e++)
            nb = nb / 10.0 ;
        ret += my_putfloat(nb, prs, put_zero);
        my_putstr("e+");
        exponent(e);
    } else {
        for (e = 0; 1 > nb; e++)
            nb = nb * 10;
        ret += my_putfloat(nb, prs, put_zero);
        my_putstr("e-");
        exponent(e);
    }
    return (ret + 4);
}

int disp_scien_majf(double nb, double prs, int put_zero)
{
    int e = 0;
    int ret = 0;
    if (nb == 0.0)
        return affichage00(prs,"E+");
    if (nb >= 1) {
        for (e = 0; nb >= 10; e++)
            nb = nb / 10.0 ;
        ret += my_putfloat(nb, prs, put_zero);
        my_putstr("E+");
        exponent(e);
    } else {
        for (e = 0; 1 > nb; e++)
            nb = nb * 10;
        ret += my_putfloat(nb, prs, put_zero);
        my_putstr("E-");
        exponent(e);
    }
    return (ret + 4);
}
