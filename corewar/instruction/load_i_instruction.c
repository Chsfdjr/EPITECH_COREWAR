/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** load_i_instruction
*/

#include "../../include/corewar_vm.h"

int ldi(info_t *info, int champ_index)
{
    if (CHAMP->nb_cycle_here == 25) {
        CHAMP->nb_cycle_here = 0;
        return get_offset(info, info->champion[champ_index]->pc + 1,
        champ_index) + 2;
    }
    if (CHAMP->nb_cycle_here == 0) {
        params_t *params = get_params(info, info->champion[champ_index]->pc + 1,
        champ_index);
        if (get_register_index(info,CHAMP->pc, champ_index, 3) < 16 &&
        get_register_index(info,CHAMP->pc, champ_index, 3) >= 0) {
            REGISTER_X(3) = return_int_from_bytes(info,CHAMP->pc +
            (params->params_one + params->params_two) % IDX_MOD, 1, REG_SIZE);
            CHAMP->carry = 1;
        } else
            CHAMP->carry = 0;
        free(params);
    }
    CHAMP->nb_cycle_here++;
    return 0;
}
