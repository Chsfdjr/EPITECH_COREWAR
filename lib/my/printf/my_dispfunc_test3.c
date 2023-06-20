/*
** EPITECH PROJECT, 2022
** my_dispfunc_test3
** File description:
** disp func for unit test
*/

#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include "include/proto_func.h"
#include <stdlib.h>

int disp_flagf_test(double nb, int prs)
{
    prs = (double)prs;
    prs = (prs == -1) ? 6. : (double)prs;
    if (!(nb == nb)) {
        my_putstr("nan");
        return 3;
    }
    if (4.0 / nb == 0) {
        my_putstr("inf");
        return 3;
    }
    return my_putfloat(nb, prs, 0);
}

int disp_flagf_maj_test(double nb, int prs)
{
    prs = (double)prs;
    prs = (prs == -1) ? 6. : prs;
    if (!(nb == nb)) {
        my_putstr("NAN");
        return 3;
    }
    if (4.0 / nb == 0) {
        my_putstr("INF");
        return 3;
    }
    return my_putfloat(nb, prs, 0);
}

int disp_flagg_test(double nb, int prs)
{
    int exp = get_exp(nb);
    double prs_copy;
    char *nb_int;

    prs = (prs == -1) ? 6. : (double)prs;
    if (nb == 0) {
        my_putstr("0");
        return 1;
    }
    if (prs == 0. && exp == 0) {
        nb_int = my_putnbr_base(nb, "0123456789");
        my_putstr(nb_int);
        return my_strlen_free(nb_int);
    }
    if (exp < -4 || exp >= prs)
        return disp_scienf(nb, (prs > exp) ? prs : prs - exp, 1);
    prs = prs - (double)exp - 1.;
    return my_putfloat(nb, prs, 1);
}

int disp_flagg_maj_test(double nb, int prs)
{
    int exp = get_exp(nb);

    prs = (prs == -1) ? 6 : (double)prs;
    if (nb == 0) {
        my_putstr("0");
        return 1;
    }
    if (exp < -4 || exp >= prs)
        return disp_scien_majf(nb, prs, 1);
    prs = prs - get_exp(nb) - 1;
    if (prs > 6)
        prs = 6.;
    return my_putfloat(nb, prs, 1);
}

int disp_flagp_test(char *ptr, int prs)
{
    long nb = (long)&ptr[0];
    char *str = my_putnbr_base(nb, "0123456789abcdef");
    int ret = 0;

    if (ptr == NULL) {
        my_putstr("(nil)");
        return 5;
    }
    my_putstr("0x");
    for (; prs > my_strlen(str); prs --)
        my_putchar('0');
    my_putstr(str);
    return 2 + my_strlen_free(str);
}
