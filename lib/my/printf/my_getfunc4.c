/*
** EPITECH PROJECT, 2022
** my_getfunc4.c
** File description:
** func pour recup size sans display
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/proto_func.h"
#include <stdlib.h>

int get_scienf(double nb, double prs, int put_zero)
{
    int e = 0;
    int ret = 0;

    if (nb == 0)
        return 12;
    if (nb >= 1) {
        for (e = 0; nb >= 10; e ++)
            nb = nb / 10.0;
        ret += my_getfloat(nb, prs, put_zero);
    } else {
        for (e = 0; 1 > nb; e ++)
            nb = nb * 10;
        ret += my_getfloat(nb, prs, put_zero);
    }
    return ret + 4;
}

int get_scien(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);
    int ret = 0;

    prs = (prs == -1) ? 6 : prs;
    if (!(nb == nb))
        return 3;
    if (4 / nb == 0)
        return 3;
    if (nb < 0. || recup_flag(format) == '+') {
        nb *= (nb < 0.) ? -1. : 1.;
        ret ++;
    }
    return ret + get_scienf(nb, prs, 0);
}

int get_flagg(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);
    int exp;
    int sign = get_flagg_neg(nb);
    if (get_inf_or_nan(nb) == 1)
        return 3;
    nb *= sign;
    exp = get_exp(nb);
    prs = (prs == -1) ? 6. : prs;
    if (nb == 0)
        return 1;
    if (prs == 0. && exp == 0)
        return my_strlen_free(my_putnbr_base(nb, "0123456789"));
    if (exp < -4 || exp >= prs)
        return get_scienf(nb, prs, 1);
    prs = prs - get_exp(nb) - 1;
    if (prs > 6)
        prs = 6.;
    return ((sign < 0 || recup_flag(format) == '+') ? 1 : 0)
        + my_getfloat(nb, prs, 1);
}

int get_flagp(va_list list_param, char *format, int prs)
{
    char *ptr = va_arg(list_param, void *);
    long nb = (long)&ptr[0];
    char *str = my_putnbr_base(nb, "0123456789abcdef");
    int ret = 2;

    if (ptr == NULL)
        return 5;
    for (; prs > my_strlen(str); prs --)
        ret ++;
    return ret + my_strlen_free(str);
}
