/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** store_i_instruction
*/

#include "../../include/corewar_vm.h"

int sti_nb_cycle(info_t *info, int champ_index)
{
    CHAMP->nb_cycle_here = 0;
    return get_offset(info,info->champion[champ_index]->pc + 1,champ_index) + 2;
}

int sti(info_t *info, int champ_index)
{
    int index1 = 0;

    if (CHAMP->nb_cycle_here == 25)
        return sti_nb_cycle(info,champ_index);
    index1 = get_register_index(info,CHAMP->pc,champ_index,1);
    if (CHAMP->nb_cycle_here == 0
    && what_type_is_it(info->arena[(CHAMP->pc + 1) %
    MEM_SIZE],1) == IS_REG && index1 >= 0 && index1 <= 15) {
        params_t *params = get_params(info, info->champion[champ_index]->pc + 1,
        champ_index);
        info->arena[(CHAMP->pc + params->params_one + params->params_two
        % IDX_MOD) % MEM_SIZE] = REGISTER_X(1);
        free(params);
    }
    CHAMP->nb_cycle_here++;
    return 0;
}
