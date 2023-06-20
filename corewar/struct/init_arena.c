/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** init_arena
*/

#include "../../include/corewar_vm.h"

void init_arena(info_t *info, int ac, char **av)
{
    int i_champ = 0;

    info->arena = malloc(sizeof(unsigned char) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        info->arena[i] = 0;
    for (int i = 1; av[i]; i++)
        if (my_strncmp_inv(av[i], ".cor", 4) == 0 && is_a_champ(av[i])) {
            create_champ_string(av[i], info->arena, info->champion[i_champ]);
            i_champ++;
        }
}
