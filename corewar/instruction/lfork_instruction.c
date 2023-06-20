/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** lfork_instruction
*/

#include "../../include/corewar_vm.h"


int lfork(info_t *info, int champ_index)
{
    int i;
    int coord;

    if (CHAMP->nb_cycle_here == 1000) {
        CHAMP->nb_cycle_here = 0;
        return 3;
    }
    if (CHAMP->nb_cycle_here == 0 && return_int_from_bytes(info, CHAMP->pc + 1,
    0, IND_SIZE) != 0) {
        for (i = 0; info->champion[i]; i++);
        coord = CHAMP->pc + return_int_from_bytes(info, CHAMP->pc + 1, 0,
        IND_SIZE) % MEM_SIZE;
        info->champion = realloc(info->champion,sizeof(champion_t) * (i));
        init_fork(info, champ_index, i, coord);
        info->champion[i + 1] = NULL;
    }
    CHAMP->nb_cycle_here++;
    return 0;
}
