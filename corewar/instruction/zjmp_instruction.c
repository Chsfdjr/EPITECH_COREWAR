/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** zjmp_instruction
*/

#include "../../include/corewar_vm.h"

int zjump(info_t *info, int champ_index)
{
    int coord;
    if (CHAMP->nb_cycle_here == 20) {
        CHAMP->nb_cycle_here = 0;
        return 3;
    }
    if (CHAMP->nb_cycle_here == 0) {
        coord = return_int_from_bytes(info, CHAMP->pc, 0,IND_SIZE);
        if (CHAMP->carry != 0)
            CHAMP->pc = ((CHAMP->pc + coord % IDX_MOD) % MEM_SIZE);
    }
    CHAMP->nb_cycle_here++;
    return 0;
}
