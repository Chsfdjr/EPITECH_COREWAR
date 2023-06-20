/*
** EPITECH PROJECT, 2022
** my_dispfunc4.c
** File description:
** fonctions pour diplay flag
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/proto_func.h"
#include <stdlib.h>
#include <stdio.h>

double round_double(double nb, double prs)
{
    double mult = my_compute_power_rec(10, prs + 2);
    int nb_check;

    nb *= mult;
    nb_check = (int)nb % 100;
    if (nb_check >= 50)
        nb += (100 - nb_check);
    else
        nb -= nb_check;
    return (nb / mult);
}

double my_putfloat_middle(int *ret, double nb, double prs)
{
    char *a = my_putnbr_base(nb, "0123456789");
    double mult = my_compute_power_rec(10, prs);

    if (my_strlen(a) == 0) {
        my_putchar('0');
        *ret += 1;
    }
    my_putchar('.');
    *ret += 1;
    nb = (nb - (int)nb) * mult;
    nb = round_double(nb, prs);
    free(a);
    return nb;
}

//put_zero permet de mettre des zéros à la fin ou non
int my_putfloat(double nb, double prs, int put_zero)
{
    int nbentier = nb;
    int ret = 0;
    double mult = my_compute_power_rec(10, prs);
    char *a = my_putnbr_base(nb, "0123456789");
    char *strnb;

    my_putstr(a);
    if ((put_zero == 1 && (int)nb * mult == (int)(nb * mult)) || prs <= 0)
        return my_strlen_free(a);
    nb = my_putfloat_middle(&ret, nb, prs);
    for (prs; nb < my_compute_power_rec(10, prs - 1); prs -= 1) {
        my_putchar('0');
        ret += 1;
    }
    strnb = my_putnbr_base(nb, "0123456789");
    if (put_zero == 1)
        return ret + putstr_non_char(strnb, '0') + my_strlen_free(a);
    my_putstr(strnb);
    return ret + my_strlen_free(a) + my_strlen_free(strnb);
}

int disp_flagf(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);

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
    if (nb < 0. || recup_flag(format) == '+') {
        my_putchar((nb < 0.) ? '-' : '+');
        nb *= (nb < 0.) ? -1. : 1.;
    }
    return my_putfloat(nb, prs, 0);
}

int disp_flagf_maj(va_list list_param, char *format, int prs)
{
    double nb = va_arg(list_param, double);

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
    if (nb < 0. || recup_flag(format) == '+') {
        my_putchar((nb < 0.) ? '-' : '+');
        nb *= (nb < 0) ? -1. : 1.;
    }
    return my_putfloat(nb, prs, 0);
}
