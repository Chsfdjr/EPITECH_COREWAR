/*
** EPITECH PROJECT, 2022
** my_getfunc3.c
** File description:
** troisième partie des flags pour printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/proto_func.h"

int get_octal(va_list list_param, char *format, int prs)
{
    unsigned int nb = va_arg(list_param, unsigned int);
    int ret = 0;
    char *octal = my_putnbr_base(nb, "01234567");
    if (nb == 0)
        return 1;
    if (recup_flag(format) == '#') {
        ret ++;
        prs --;
    }
    for (; prs > my_strlen(octal); prs --)
        ret ++;
    return ret + my_strlen_free(octal);
}

int my_getfloat(double nb, double prs, int put_zero)
{
    int nbentier = nb;
    int ret = 0;
    double mult = my_compute_power_rec(10, prs);
    char *a = my_putnbr_base(nb, "0123456789");
    char *strnb;

    if ((put_zero == 1 && (int)nb * mult == (int)(nb * mult)) || (prs <= 0.))
        return my_strlen_free(a);
    if (my_strlen(a) == 0)
        ret += 1;
    ret += 1;
    nb = (nb - (int)nb) * mult;
    nb = round_double(nb, prs);
    for (prs; nb < my_compute_power_rec(10, prs - 1); prs -= 1)
        ret += 1;
    strnb = my_putnbr_base(nb, "0123456789");
    if (put_zero == 1)
        return ret + getstr_non_char(strnb, '0') + my_strlen_free(a);
    return ret + my_strlen_free(a) + my_strlen_free(strnb);
}

int get_flagf(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);
    int ret = 0;
    prs = (prs == -1) ? 6. : (double)prs;
    if (!(nb == nb))
        return 3;
    if (4.0 / nb == 0)
        return 3;
    if (nb < 0.0 || recup_flag(format) == '+') {
        ret ++;
        nb *= (nb < 0.) ? -1. : 1.;
    }
    return ret + my_getfloat(nb, prs, 0);
}

int getstr_non_char(char *nb, char not)
{
    int index = my_strlen(nb) - 1;
    while (nb[index] == not)
        index -= 1;
    index += 1;
    free(nb);
    return index;
}
