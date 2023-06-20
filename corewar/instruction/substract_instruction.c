/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** substract_instruction
*/

#include "../../include/corewar_vm.h"

void sub_second(info_t *info, int champ_index)
{
    int index[3];
    index[0] = get_register_index(info, CHAMP->pc, champ_index, 1);
    index[1] = get_register_index(info, CHAMP->pc, champ_index, 2);
    index[2] = get_register_index(info, CHAMP->pc, champ_index, 3);
    if (index[0] < 0 || index[0] >= 16 || index[1] < 0 || index[1] >= 16
    || index[2] < 0 || index[2] >= 16 )
        CHAMP->carry = 0;
    else {
        CHAMP->registre[index[2]] =
        CHAMP->registre[index[0]] - CHAMP->registre[index[1]];
        CHAMP->carry = 1;
    }
}

int sub(info_t *info, int champ_index)
{
    if (CHAMP->nb_cycle_here == 10) {
        CHAMP->nb_cycle_here = 0;
        int offset = get_offset(info, info->champion[champ_index]->pc + 1,
        champ_index) + 2;
        return offset;
    }
    if (CHAMP->nb_cycle_here == 0)
        sub_second(info, champ_index);
    CHAMP->nb_cycle_here++;
    return 0;

}
