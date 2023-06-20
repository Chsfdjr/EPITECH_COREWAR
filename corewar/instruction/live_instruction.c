/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** live
*/

#include "../../include/corewar_vm.h"

int live(info_t *info, int champ_index)
{
    if (CHAMP->nb_cycle_here == 10) {
        CHAMP->nb_cycle_here = 0;
        return 5;
    }
    if (CHAMP->nb_cycle_here == 0) {
        CHAMP->said_live = true;
        info->count_live++;
        info->nbr_last_champ_alive = champ_index;
        my_printf("The player %d(%s) is alive.\n",CHAMP->prog_nbr,CHAMP->name);
    }
    CHAMP->nb_cycle_here++;
    return 0;
}
