/*
** EPITECH PROJECT, 2022
** my_dispfunc_test2
** File description:
** disp fonc for unit test
*/

#include "include/my.h"
#include <stdarg.h>
#include "include/proto_func.h"
#include <stdlib.h>

int disp_binary_test(unsigned int nb, char *format, int prs)
{
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

int disp_hexa_test(unsigned int nb, char *format, int prs)
{
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

int disp_hexa_maj_test(unsigned int nb, char *format, int prs)
{
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

int disp_unsigned_test(unsigned int nb, int prs)
{
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

int disp_octal_test(unsigned int nb, char *format, int prs)
{
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
