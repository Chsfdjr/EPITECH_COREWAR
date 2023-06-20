/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** xor_instruction
*/

#include "../../include/corewar_vm.h"

int xor_instruction(info_t *info, int champ_index)
{
    int index;
    if (CHAMP->nb_cycle_here == 6) {
        CHAMP->nb_cycle_here = 0;
        return get_offset(info, info->champion[champ_index]->pc + 1,
        champ_index) + 2;
    }
    if (CHAMP->nb_cycle_here == 0) {
        params_t *params = get_params(info, info->champion[champ_index]->pc + 1,
        champ_index);
        index = get_register_index(info, CHAMP->pc, champ_index, 3);
        CHAMP->carry = params->params_one ^ params->params_two;
        if (index < 0 || index >= REG_NUMBER)
            CHAMP->carry = 0;
        else {
            REGISTER_X(3) = params->params_one ^ params->params_two;
        }
    }
    CHAMP->nb_cycle_here++;
    return 0;
}
