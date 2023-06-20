/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** corewar_dump
*/

#include "../../include/corewar_vm.h"

int corewar_dump(int ac, char **av, info_t *info, int index)
{
    if (av[index + 1] != NULL
    && my_strcmp(av[index], "-dump") == 1 && my_getnbr(av[index + 1]) >= 0) {
        info->cycle->cycle_dump = my_getnbr(av[index + 1]);
        return 1;
    }
    return 0;
}
