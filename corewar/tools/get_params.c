/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** get_params
*/

#include "../include/corewar_vm.h"

int return_int_from_bytes(info_t *info, int index_arena,
int params, int nb_bytes)
{
    int num = 0;
    for (int i = 0; i < nb_bytes; i++) {
        if (info->arena[(index_arena + i) % MEM_SIZE] != 0)
            num += info->arena[(index_arena + i) % MEM_SIZE];
        if (info->arena[(index_arena + i) % MEM_SIZE] != 0
        && my_compute_power_rec(16, (nb_bytes - i)) > 16)
            num += my_compute_power_rec(16, (nb_bytes - i));
    }
    return (num);
}

int get_one_param(info_t *info, int params, int champ_index, int offset)
{
    int num = what_type_is_it(info->arena[CHAMP->pc % MEM_SIZE], params);
    int index_reg;

    if (num == 0 && (int) info->arena[(CHAMP->pc + offset) % MEM_SIZE] > 0
    && (int) info->arena[(CHAMP->pc + offset) % MEM_SIZE] <= 16) {
        index_reg = ((int) info->arena[(CHAMP->pc + offset) % MEM_SIZE]) - 1;
        return CHAMP->registre[index_reg];
    }
    if (num == 1 && info->arena[(CHAMP->pc - 1) % MEM_SIZE] >= 9
    && info->arena[(CHAMP->pc - 1) % MEM_SIZE] <= 15
    && info->arena[(CHAMP->pc - 1) % MEM_SIZE] != 13)
        return return_int_from_bytes(info, CHAMP->pc + offset, offset,IND_SIZE);
    if (num == 1)
        return return_int_from_bytes(info, CHAMP->pc + offset, offset,DIR_SIZE);
    if (num == 2) {
        return info->arena[return_int_from_bytes(info,
        CHAMP->pc + offset, offset, IND_SIZE) % MEM_SIZE];
    }
    return 0;
}

params_t *get_params(info_t *info, int index_arena, int champ_index)
{
    params_t *params = malloc(sizeof(params_t));

    CHAMP->pc++;
    params->offset = 1;
    params->params_one = get_one_param(info, 1, champ_index, params->offset);
    params->offset += what_size_is_it(info->arena[index_arena % MEM_SIZE], 1,
    info->arena[(index_arena - 1) % MEM_SIZE]);
    params->params_two = get_one_param(info, 2, champ_index, params->offset);
    params->offset += what_size_is_it(info->arena[index_arena % MEM_SIZE], 2,
    info->arena[(index_arena - 1) % MEM_SIZE]);
    params->params_three = get_one_param(info, 3, champ_index, params->offset);
    params->offset += what_size_is_it(info->arena[index_arena % MEM_SIZE], 3,
    info->arena[(index_arena - 1) % MEM_SIZE]);
    params->params_four = get_one_param(info, 4, champ_index, params->offset);
    params->offset += what_size_is_it(info->arena[index_arena % MEM_SIZE], 4,
    info->arena[(index_arena - 1) % MEM_SIZE]);
    CHAMP->pc--;
    return params;
}

int get_offset(info_t *info, int index_arena, int champ_index)
{
    CHAMP->pc++;
    int offset = 0;
    offset += what_size_is_it(info->arena[index_arena % MEM_SIZE], 1,
    info->arena[(index_arena - 1) % MEM_SIZE]);
    offset += what_size_is_it(info->arena[index_arena % MEM_SIZE], 2,
    info->arena[(index_arena - 1) % MEM_SIZE]);
    offset += what_size_is_it(info->arena[index_arena % MEM_SIZE], 3,
    info->arena[(index_arena - 1) % MEM_SIZE]);
    offset += what_size_is_it(info->arena[index_arena % MEM_SIZE], 4,
    info->arena[(index_arena - 1) % MEM_SIZE]);
    CHAMP->pc--;
    return offset;
}

int get_register_index(info_t *info, int index_arena, int champ_index,
int nb_param)
{
    int offset = 1;
    int index_reg = 0;
    for (int i = 1; i < nb_param; i++) {
        offset += what_size_is_it(info->arena[(index_arena + 1 ) % MEM_SIZE], i,
        info->arena[(index_arena) % MEM_SIZE]);
    }
    CHAMP->pc++;
    index_reg = (int) info->arena[(CHAMP->pc + offset) % MEM_SIZE];
    CHAMP->pc--;
    return index_reg - 1;
}
