/*
** EPITECH PROJECT, 2022
** my_getsign.c
** File description:
** task05 day04
*/

#include <stdio.h>

int my_getsign(char const *str, int ind_deb)
{
    int nbr = 1;

    while (ind_deb >= 1) {
        if (str[ind_deb - 1] == '-') {
            nbr *= -1;
        }
        if (str[ind_deb - 1] != '+' && str[ind_deb - 1] != '-') {
            return nbr;
        }
        ind_deb -= 1;
    }
    return nbr;
}
