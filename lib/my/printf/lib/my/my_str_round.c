/*
** EPITECH PROJECT, 2022
** my_str_round
** File description:
** round str
*/
#include <stdio.h>

int my_strlen(char const *str);

int first_occ(char *str, char c)
{
    int i = 0;
    for (; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return 84;
}

char *my_str_round(char *str, char *base,int prs)
{
    int i = prs;
    int midbase = my_strlen(base) / 2;
    if (first_occ(base,str[i]) >= first_occ(base,base[midbase])) {
        for (;str[i] == base[my_strlen(base) - 1];i--)
            str[i] = base[0];
        str[i - 1] = str[i - 1] + 1;
    }
    str[prs] = '\0';
    return str;
}
