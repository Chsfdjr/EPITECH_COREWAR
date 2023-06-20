/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** add_instruction
*/

#include "../../include/corewar_vm.h"

void debug_arena(int n, info_t *info, int champ_index)
{
    my_printf("[");
    for (int i = 0; i < n; i++)
        my_printf("%2.X, ", info->arena[(CHAMP->pc + (i - n)) % MEM_SIZE]);
    my_printf("%2.X, ", info->arena[CHAMP->pc % MEM_SIZE]);
    for (int i = 1; i <= n; i++) {
        if (i == n)
            my_printf("%d]\n", info->arena[(CHAMP->pc + i) % MEM_SIZE]);
        else
            my_printf("%d, ", info->arena[(CHAMP->pc + i) % MEM_SIZE]);
    }
}

void add_second(info_t *info, int champ_index)
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
        CHAMP->registre[index[1]] + CHAMP->registre[index[0]];
        CHAMP->carry = 1;
    }
}

int add(info_t *info, int champ_index)
{
    if (CHAMP->nb_cycle_here == 10) {
        CHAMP->nb_cycle_here = 0;
        return get_offset(info, info->champion[champ_index]->pc + 1,
        champ_index) + 2;
    }
    if (CHAMP->nb_cycle_here == 0)
        add_second(info, champ_index);
    CHAMP->nb_cycle_here++;
    return 0;
}
