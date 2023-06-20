/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** projet printf
*/

#include "include/my.h"
#include "include/proto_func.h"
#include <stdarg.h>

int my_put_param(char flag, va_list list_param, char *format, int prs)
{
    char list[] = "csdiSbxXoufFeEpagGA%";
    int (*tab_func[])() = {&dispchar, &dispstr, &dispnb,
        &dispnb, &disp_majs, &disp_binary, &disp_hexa, &disp_hexa_maj,
        &disp_octal, &disp_unsigned, &disp_flagf, &disp_flagf_maj,
        &disp_scien, &disp_scien_maj, &disp_flagp, &disp_sc_hex,
        &disp_flagg, &disp_flagg_maj, &disp_sc_hex_maj, &disp_percent};
    int (*ptrf)();

    for (int i = 0; i < my_strlen(list); i ++) {
        if (flag == list[i]) {
            ptrf = tab_func[i];
            return ptrf(list_param, format, prs);
        }
    }
    my_putchar('%');
    my_putchar(flag);
    return 2;
}

int my_get_param(char flag, va_list list_param, char *format, int prs)
{
    char list[] = "csdiSbxXoufFeEpagGA%";
    int (*tab_func[])() = {&get_char, &getstr, &getnb,
        &getnb, &get_majs, &get_binary, &get_hexa, &get_hexa,
        &get_octal, &get_unsigned, &get_flagf, &get_flagf,
        &get_scien, &get_scien, &get_flagp, &get_sc_hex,
        &get_flagg, &get_flagg, &get_sc_hex, &get_pourcent};
    int (*ptrf)();

    for (int i = 0; i < my_strlen(list); i ++) {
        if (flag == list[i]) {
            ptrf = tab_func[i];
            return ptrf(list_param, format, prs);
        }
    }
    return 2;
}

int my_printf_middle(char const *restrict format, int *i,
                    va_list l_param, va_list copy)
{
    int ret = 0;
    int temp = 0;

    if (format[*i] == '%') {
        temp = get_len(format, *i);
        ret = (temp == -1) ? -1 : ret + my_putformat(format, *i, l_param, copy);
        *i += temp + 1;
    } else {
        my_putchar(format[*i]);
        *i += 1;
        ret ++;
    }
    return ret;
}

int my_printf(const char *restrict format, ...)
{
    va_list list_param;
    va_list copy;
    int i = 0;
    int ret = 0;
    int temp;

    va_start(copy, format);
    va_start(list_param, format);
    while (i < my_strlen(format)) {
        temp = my_printf_middle(format, &i, list_param, copy);
        if (temp == -1)
            return -1;
        ret += temp;
    }
    va_end(copy);
    va_end(list_param);
    return ret;
}
