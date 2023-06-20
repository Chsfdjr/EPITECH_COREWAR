/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** my_strncmp_inv
*/

#include "../include/corewar_vm.h"

int my_strncmp_inv(char const *s1, char const *s2, int n)
{
    int i = my_strlen(s1) - n;
    int y = 0;
    while ((s1[i] != '\0' && s2[y] != '\0')) {
        if (s1[i] != s2[y])
            return 1;
        i++;
        y++;
    }
    return 0;
}
