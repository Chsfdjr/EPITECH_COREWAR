/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** load_instruction
*/

#include "../../include/corewar_vm.h"

int get_lld_value(info_t *info, int champ_index, int offset)
{
    int num = what_type_is_it(info->arena[(CHAMP->pc + offset) % MEM_SIZE], 1);
    if (num == IS_DIR)
        return return_int_from_bytes(info, CHAMP->pc + offset + 1, 1,DIR_SIZE);
    if (num == IS_INDIR)
        return return_int_from_bytes(info,CHAMP->pc + return_int_from_bytes(\
info, CHAMP->pc + offset + 1, 1, IND_SIZE), 0, REG_SIZE);
    return 0;
}

int lld(info_t *info, int champ_index)
{
    if (CHAMP->nb_cycle_here == 10) {
        CHAMP->nb_cycle_here = 0;
        return get_offset(info, info->champion[champ_index]->pc + 1,
        champ_index) + 2;
    }
    if (CHAMP->nb_cycle_here == 0) {
        params_t *params = get_params(info, info->champion[champ_index]->pc + 1,
        champ_index);
        if (get_register_index(info, CHAMP->pc, champ_index, 2) < 16 &&
        get_register_index(info, CHAMP->pc, champ_index, 2) >= 0) {
            REGISTER_X(2) = get_lld_value(info, champ_index, 1);
            CHAMP->carry = 1;
        } else
            CHAMP->carry = 0;
        free(params);
    }
    CHAMP->nb_cycle_here++;
    return 0;
}
