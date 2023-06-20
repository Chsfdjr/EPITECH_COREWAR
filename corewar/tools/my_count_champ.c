/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** my_count_champ
*/

#include "../include/corewar_vm.h"

int count_champ(int ac, char ** av)
{
    int count = 0;
    for (int i = 1; av[i]; i++)
        if (my_strncmp_inv(av[i], ".cor", 4) == 0 && is_a_champ(av[i]))
            count++;
    return count;
}
