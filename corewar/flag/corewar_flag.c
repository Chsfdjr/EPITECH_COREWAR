/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** corewar_flag
*/

#include "../../include/corewar_vm.h"

int corewar_flag(int ac, char **av, info_t *info)
{
    corewar_h(ac, av, info);
    for (int i = 1; i < ac; i++)
        i += corewar_dump(ac, av, info, i);
    corewar_champion_flag(ac, av, info);
    return 0;
}
