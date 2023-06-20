/*
** EPITECH PROJECT, 2022
** my_dispfunc_test1
** File description:
** dispfun for unit tests
*/

#include <stdarg.h>
#include "include/my.h"
#include <stdlib.h>
#include "include/proto_func.h"

int dispnb_test(int nb, int prs)
{
    int ret = get_diz(nb);
    int nb_copy = nb;

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    for (int i = prs; ret < i; i --)
        my_putchar('0');
    my_put_nbr(nb);
    return (ret > prs) ? ret : prs;
}

int dispstr_test(char *str, int prs)
{
    if (prs < 0) {
        my_putstr(str);
        return my_strlen(str);
    }
    return my_putnstr(str, prs);
}

int dispchar_test(char c)
{
    my_putchar(c);
    return 1;
}

void octal_zero_test(char *octal)
{
    int compteur = my_strlen(octal);

    for (; compteur < 3; compteur ++)
        my_putchar('0');
}

int disp_majs_test(char *str, int prs)
{
    int ret = 0;
    char *octal;
    int compteur;

    for (int i = 0; i < my_strlen(str); i ++) {
        if (char_isprint(str[i]) == 0) {
            my_putchar('\\');
            octal = my_putnbr_base(str[i], "01234567");
            compteur = my_strlen(octal);
            octal_zero_test(octal);
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
