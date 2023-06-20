/*
** EPITECH PROJECT, 2022
** my_showmem.c
** File description:
** show mem
*/
#include <stdio.h>
int my_put_hex(int nb);
void my_putchar(char c);
void my_putstr(char *str);
int my_put_nbr(int nb);
int my_put_hex_without_null(int nb)
{
    if (nb > 15)
        my_put_hex_without_null(nb / 16);
    if (nb == 0)
        my_putstr("  ");
    else if ((nb % 16) > 9)
        my_putchar((nb % 16) + 87);
    else
        my_putchar((nb % 16) + 48);
}

void my_put_adress(int adress)
{
    if (adress < 16)
        my_putstr("0000000");
    if (adress < 256 && adress >= 16)
        my_putstr("000000");
    if (adress < 4096 && adress >= 256)
        my_putstr("00000");
    if (adress < 65536 && adress >= 4096)
        my_putstr("0000");
    if (adress < 1048576 && adress >= 65536)
        my_putstr("000");
    if (adress < 16777216 && adress >= 1048576)
        my_putstr("00");
    if (adress < 268435456 && adress >= 16777216)
        my_putchar('0');
    my_put_hex(adress);
}

int my_put_hexchar(char const *str, int j)
{
    int i = 0;
    char line[16];
    while (i != 16) {
        if (str[j] < 16 && str[j] > 0)
            my_putchar('0');
        my_put_hex_without_null(str[j]);
        if ((str[j] < 32 || str[j] > 126) && str[j] > 0)
            line[i] = '.';
        else
            line[i] = str[j];
        i++;
        j++;
        if (i % 2 == 0)
                my_putchar(' ');
    }
    my_putstr(line);
    my_putchar('\n');
    return j;
}

int my_showmem(char const *str, int size)
{
    int j = 0;
    int adress = 0;
    while (size > 0) {
        my_put_adress(adress);
        my_putstr(": ");
        j = my_put_hexchar(str,j);
        size -= 16;
        adress += 16;
    }
    return 0;
}
