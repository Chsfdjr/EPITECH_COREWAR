/*
** EPITECH PROJECT, 2022
** my_dispfunc2.c
** File description:
** fonctions pour display printf
*/

#include "include/my.h"
#include <stdarg.h>
#include "include/proto_func.h"
#include <stdlib.h>

int disp_binary(va_list list_param, char *format, int prs)
{
    unsigned int nb = va_arg(list_param, unsigned int);
    char *binary = my_putnbr_base(nb, "01");
    int ret = 0;
    if (recup_flag(format) == '#' && nb != 0) {
        my_putstr("0b");
        ret ++;
    }
    if (nb == 0) {
        my_putchar('0');
        free(binary);
        return 1;
    }
    for (; prs > my_strlen(binary); prs --)
        my_putchar('0');
    my_putstr(binary);
    return ret + my_strlen_free(binary);
}

int disp_hexa(va_list list_param, char *format, int prs)
{
    unsigned int nb = va_arg(list_param, unsigned int);
    char *hexa = my_putnbr_base(nb, "0123456789abcdef");
    int ret = 0;
    if (recup_flag(format) == '#' && nb != 0) {
        my_putstr("0x");
        ret += 2;
    }
    if (nb == 0) {
        my_putchar('0');
        free(hexa);
        return 1;
    }
    for (; prs > my_strlen(hexa); prs --)
        my_putchar('0');
    my_putstr(hexa);
    return ret + my_strlen_free(hexa);
}

int disp_hexa_maj(va_list list_param, char *format, int prs)
{
    unsigned int nb = va_arg(list_param, unsigned int);
    char *hexa = my_putnbr_base(nb, "0123456789ABCDEF");
    int ret = 0;
    if (recup_flag(format) == '#' && nb != 0) {
        my_putstr("0X");
        ret += 2;
    }
    if (nb == 0) {
        my_putchar('0');
        free(hexa);
        return 1;
    }
    for (; prs > my_strlen(hexa); prs --)
        my_putchar('0');
    my_putstr(hexa);
    return my_strlen_free(hexa);
}

int disp_unsigned(va_list list_param, char *format, int prs)
{
    unsigned int nb = va_arg(list_param, unsigned int);
    char *unsign = my_putnbr_base(nb, "0123456789");
    int ret = 0;
    if (nb == 0) {
        my_putchar('0');
        free(unsign);
        return 1;
    }
    for (; prs > my_strlen(unsign); prs --)
        my_putchar('0');
    my_putstr(unsign);
    return ret + my_strlen_free(unsign);
}

int get_diz(long nb)
{
    int ret = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        nb *= -1;
    }
    for (; nb >= 1; nb /= 10)
        ret ++;
    return ret;
}
