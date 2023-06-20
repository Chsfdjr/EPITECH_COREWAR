/*
** EPITECH PROJECT, 2022
** my_put_nbr_base2
** File description:
** put float in base n
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);
char *my_revstr(char *str);
int my_putstr(char const *str);
char my_putchar(char c);
int recup_div(long nbr, int div_base);
char *my_strcat(char *dest, char const *src);
int my_compute_power_rec(int nb, int c);
char *my_str_round(char *str, char const *base, int prs);

double neg_power_rec(int nb, int c)
{
    if (c >= 0)
        return my_compute_power_rec(nb,c);
    return (1. / my_compute_power_rec(nb, -c));
}

char *my_putint_base(double nb, char const *base)
{
    int nbr = nb;
    int div_base = my_strlen(base);
    int len_str = recup_div(nbr, div_base);
    char *str = malloc(sizeof(char) * len_str + 1);
    int i = 0;

    if (nbr < 0) {
        nbr *= -1;
        str[len_str - 1] = '-';
    }
    for (; nbr >= 1; nbr /= div_base) {
        str[i] = base[nbr % div_base];
        i ++;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}

char *my_putdec_base(double nbr, char const *base, int prs)
{
    char *str;
    int p = 0;
    double a = 0;
    int i = 1;
    str = malloc(sizeof(char) * (prs + 1) +1);
    str[0] = '.';
    nbr -= (int)nbr;
    if (0 > nbr)
        nbr *= -1;
    for (i = 1; i != prs + 1; i++) {
        for (p = 1; nbr >= (neg_power_rec(my_strlen(base), -i) * p); p++);
        str[i] = base[p - 1];
        nbr -= (neg_power_rec(my_strlen(base), -i) * (p - 1));
        p = 0;
    }
    str[i] = '\0';
    return (my_str_round(str,base,prs));
}

char *my_putfloat_base(double nb, char const *base, int prs)
{
    char *str = my_putint_base(nb,base);
    char *str2 = my_putdec_base(nb,base,prs);
    if (nb != (int)nb)
        my_strcat(str,str2);
    free(str2);
    str2 = NULL;
    return str;
}
