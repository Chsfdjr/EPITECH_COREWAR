/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** task18 day06
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);
char *my_revstr(char *str);
int my_putstr(char const *str);
char my_putchar(char c);

int recup_div(long nbr, int div_base)
{
    int div = 0;

    if (nbr < 0)
        nbr *= -1;
    while (nbr >= 1) {
        nbr /= div_base;
        div += 1;
    }
    return div;
}

char *my_putnbr_base(long nbr, char const *base)
{
    int div_base = my_strlen(base);
    int len_str = recup_div(nbr, div_base) + 1;
    char *str = malloc(sizeof(char) * len_str + 1);
    int i = 0;

    if (nbr < 0)
        nbr *= -1;
    for (int i = 0; i < len_str; i ++)
        str[i] = 0;
    for (; nbr >= 1; nbr /= div_base) {
        str[i] = base[nbr % div_base];
        i ++;
    }
    str[len_str] = '\0';
    my_revstr(str);
    return str;
}
