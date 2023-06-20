/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** compare
*/
#include <stddef.h>

int compare_ascii(char const *s1, char const *s2)
{
    if (s1[0] < s2[0])
        return -1;
    else
        return 0;
}

int my_strcmp (char const *s1, char const *s2)
{
    while (s1[0] != '\0' || s2[0] != '\0') {
        if (s1[0] != s2[0])
            return compare_ascii(s1,s2);
        s1++;
        s2++;
    }
    return 1;
}
