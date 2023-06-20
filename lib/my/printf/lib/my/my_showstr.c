/*
** EPITECH PROJECT, 2022
** my_showstr.c
** File description:
** task20 day06
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_str_isprintable(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_putnbr_base(int nbr, char const *base);

int char_isprint(char c)
{
    if (!(c >= 32 && c <= 126))
        return 0;
    return 1;
}

int my_printstr(char c)
{
    char *nb_hexa = malloc(sizeof(char) * 3);

    if (char_isprint(c) == 0) {
        my_putchar('\\');
        nb_hexa = my_putnbr_base(c, "0123456789abcdef");
        if (my_strlen(nb_hexa) == 1)
            my_putchar('0');
        my_putstr(nb_hexa);
    } else {
        my_putchar(c);
    }
    return 0;
}

int my_showstr(char const *str)
{
    for (int i = 0; i < my_strlen(str); i ++)
        my_printstr(str[i]);
    return 0;
}
