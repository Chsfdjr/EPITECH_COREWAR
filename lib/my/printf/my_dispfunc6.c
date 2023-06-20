/*
** EPITECH PROJECT, 2022
** my_dispfunc6.c
** File description:
** fichiers 6 pour les flags de printf
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/proto_func.h"
#include <stdlib.h>

int get_exp(double nb)
{
    int ret = 0;

    if (nb == 0)
        return 84;
    if (nb > 1) {
        for (ret = -1; nb >= 1; ret ++)
            nb /= 10;
    } else {
        for (ret = 0; nb < 1; ret --)
            nb *= 10;
    }
    return ret;
}

int disp_flagg(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);
    int exp;
    char *nb_int;
    if (disp_inf_or_nan(nb, 0) == 1)
        return 3;
    nb *= flagg_neg(nb, format);
    exp = get_exp(nb);
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
        return disp_scienf(nb, prs, 1);
    return my_putfloat(nb, prs - (double)exp - 1., 1);
}

int disp_flagg_maj(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);
    int exp;
    char *nb_int;
    nb *= flagg_neg(nb, format);
    if (disp_inf_or_nan(nb, 1) == 1)
        return 3;
    exp = get_exp(nb);
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
        return disp_scien_majf(nb, prs, 1);
    return my_putfloat(nb, prs - (double)exp - 1., 1);
}

int putstr_non_char(char *nb, char not)
{
    int index = my_strlen(nb) - 1;
    char *ret;
    while (nb[index] == not)
        index -= 1;
    index += 1;
    ret = malloc(sizeof(char) * index + 1);
    my_strncpy(ret, nb, index);
    ret[index] = '\0';
    my_putstr(ret);
    free(nb);
    free(ret);
    return index + 1;
}

int disp_flagp(va_list list_param, char *format, int prs)
{
    char *ptr = va_arg(list_param, void *);
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
