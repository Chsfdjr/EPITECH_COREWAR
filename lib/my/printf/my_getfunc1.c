/*
** EPITECH PROJECT, 2022
** my_getfunc.c
** File description:
** fonction pour recup taille
*/

#include <stdarg.h>
#include "include/my.h"
#include <stdlib.h>
#include "include/proto_func.h"

int getnb(va_list list_param, char *format, int prs)
{
    int nb = va_arg(list_param, int);
    long nb_copy = nb;
    int ret = get_diz((nb < 0) ? nb_copy * -1 : nb);
    char *ret_str;
    if (nb < 0 || recup_flag(format) == '+')
        ret ++;
    if (nb == 0)
        return (prs > 1) ? prs : 1;
    if (prs > ret && nb < 0)
        prs ++;
    ret_str = my_putnbr_base(nb, "0123456789");
    free(ret_str);
    return (ret > prs) ? ret : prs;
}

int get_char(va_list list_param, char *format, int prs)
{
    char a = va_arg(list_param, int);
    return 1;
}

int getstr(va_list list_param, char *format, int prs)
{
    char *str = va_arg(list_param, char *);
    if (prs < 0)
        return my_strlen(str);
    return prs;
}

int get_majs(va_list list_param, char *format, int prs)
{
    char *str = va_arg(list_param, char *);
    int ret = 0;

    for (int i = 0; i < my_strlen(str); i ++) {
        if (char_isprint(str[i]) == 0)
            ret += 4;
        else
            ret ++;
    }
    return ret;
}

int get_pourcent(va_list list_param, char *format, int prs)
{
    return 1;
}
