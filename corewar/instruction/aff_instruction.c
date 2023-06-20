/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** aff_instruction
*/

#include "../../include/corewar_vm.h"

int aff(info_t *info, int champ_index)
{
    if (CHAMP->nb_cycle_here == 2) {
        CHAMP->nb_cycle_here = 0;
        return 3;
    }
    if (CHAMP->nb_cycle_here == 0) {
        params_t *params = get_params(info, info->champion[champ_index]->pc + 1,
        champ_index);
        my_printf("%c\n", params->params_one % 256);
        free(params);
    }
    CHAMP->nb_cycle_here++;
    return 0;
}
