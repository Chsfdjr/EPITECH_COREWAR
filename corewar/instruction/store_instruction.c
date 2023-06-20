/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** store_instruction
*/

#include "../../include/corewar_vm.h"

int st_nb_cycle(info_t *info, int champ_index)
{
    CHAMP->nb_cycle_here = 0;
    return get_offset(info,info->champion[champ_index]->pc + 1,champ_index) + 2;
}

int st_instruction(info_t *info, int champ_index)
{
    int index1 = 0;

    if (CHAMP->nb_cycle_here == 5)
        return st_nb_cycle(info,champ_index);
    index1 = get_register_index(info,CHAMP->pc,champ_index,1);
    if (CHAMP->nb_cycle_here == 0
    && what_type_is_it(info->arena[(CHAMP->pc + 1) %
    MEM_SIZE],1) == IS_REG && index1 >= 0 && index1 <= 15) {
        index1 = get_register_index(info,CHAMP->pc,champ_index,2);
        if (what_type_is_it(info->arena[(CHAMP->pc + 1) % MEM_SIZE],2) == IS_REG
        && index1 >= 0 && index1 <= 15) {
            REGISTER_X(1) = REGISTER_X(2);
        }
        if (what_type_is_it(info->arena[(CHAMP->pc + 1) % MEM_SIZE],2)
        == IS_INDIR)
            info->arena[((CHAMP->pc + return_int_from_bytes(info, CHAMP->pc + 3,
            1, IND_SIZE)) % IDX_MOD) % MEM_SIZE] = REGISTER_X(1);
    }
    CHAMP->nb_cycle_here++;
    return 0;
}
