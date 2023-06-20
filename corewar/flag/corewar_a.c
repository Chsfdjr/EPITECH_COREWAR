/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** corewar_n
*/

#include "../../include/corewar_vm.h"

int corewar_a(int ac, char **av, info_t *info)
{
    int mem_pos = -1;
    int champ_index = 0;

    for (int i = 1; i < ac ; i++) {
        if (my_strcmp(av[i], "-a") == 1
        && ac > i + 1 && my_str_isnum(av[i + 1]))
            mem_pos = my_getnbr(av[i + 1]);
        if (is_a_champ(av[i]) && mem_pos != -1) {
            info->champion[champ_index]->mem_pos = mem_pos % MEM_SIZE;
            mem_pos = -1;
        }
        if (is_a_champ(av[i]))
            champ_index++;
    }
    return 1;
}
