/*
** EPITECH PROJECT, 2022
** my_dispunf5
** File description:
** disp func 5
*/

#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/proto_func.h"

char *disp_sc_hexpos(double nb, char signe, int prs, char *hex)
{
    int p = 0;
    for (; nb >= 2; p++)
        nb = nb / 2.0 ;
    hex = my_putfloat_base(nb, "0123456789abcdef", prs);
    my_putstr("0x");
    putstr_non_char(hex,'0');
    my_putchar('p');
    my_putchar(signe);
    my_put_nbr(p);
    return hex;
}

int disp_sc_hex(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);
    char *hex;
    int p = 0;
    prs = (double)prs + 1.;
    if (nb >= 1)
        hex = disp_sc_hexpos(nb,'+',prs,hex);
    else {
        for (p = 0; 1 > nb; p++)
            nb = nb * 2;
        hex = my_putfloat_base(nb, "0123456789abcdef", prs);
        my_putstr("0x");
        putstr_non_char(hex,'0');
        my_putstr("p-");
        my_put_nbr(p);
    }
    p = my_strlen(hex);
    free(hex);
    hex = NULL;
    return (p + 6);
}

char *disp_sc_hexpos_maj(double nb, char signe, int prs, char *hex)
{
    int p = 0;
    for (; nb >= 2; p++)
        nb = nb / 2.0 ;
    hex = my_putfloat_base(nb, "0123456789ABCDEF", prs);
    my_putstr("0X");
    putstr_non_char(hex,'0');
    my_putchar('P');
    my_putchar(signe);
    my_put_nbr(p);
    return hex;
}

int disp_sc_hex_maj(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);
    char *hex;
    int p = 0;
    prs = prs + 1.;
    if (nb >= 1)
        hex = disp_sc_hexpos_maj(nb,'+',prs,hex);
    else {
        for (p = 0; 1 > nb; p++)
            nb = nb * 2;
        hex = my_putfloat_base(nb, "0123456789ABCDEF", prs);
        my_putstr("0X");
        putstr_non_char(hex,'0');
        my_putstr("P-");
        my_put_nbr(p);
    }
    p = my_strlen(hex);
    free(hex);
    hex = NULL;
    return (p + 6);
}

int get_sc_hex(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);
    char *hex;
    int p = 0;
    prs = (double)prs + 1.;
    if (nb >= 1) {
        for (; nb >= 2; p++)
            nb /= 2.0;
        p = nb_diz(p);
        hex = my_putfloat_base(nb, "0123456789ABCDEF", prs);
        p += 4 + getstr_non_char(hex,'0');
    } else {
        for (p = 0; 1 > nb; p++)
            nb /= 2.0;
        p = nb_diz(p);
        hex = my_putfloat_base(nb, "0123456789ABCDEF", prs);
        p += getstr_non_char(hex,'0') + 4;
    }
    free(hex);
    hex = NULL;
    return (p);
}
