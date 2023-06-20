/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** corewar
*/

#include "../include/corewar_vm.h"

int which_instruction(info_t *info, int champ_index)
{
    int (*tab_instruction[16])(info_t *info, int champ_index) = {&live,
    &ld_instruction, &st_instruction, &add, &sub, &and_instruction,
    &or_instruction, &xor_instruction,
    &zjump, &ldi, &sti, &fork_instruction, &lld, &lldi, &lfork, &aff};
    while (info->arena[info->champion[champ_index]->pc % MEM_SIZE] < 1
    || info->arena[info->champion[champ_index]->pc % MEM_SIZE] > 16) {
        info->champion[champ_index]->pc++;
    }
    return tab_instruction[
        (int) info->arena[CHAMP->pc % MEM_SIZE] - 1](info, champ_index);
}

void the_champ_is_dead(info_t *info, int i)
{
    for (int champ_index = 0;info->champion[champ_index] != NULL; champ_index++)
        if (CHAMP->is_alive && CHAMP->prog_nbr == info->champion[i]->prog_nbr)
            return;
    info->nbr_champ_alive--;
}

void die_champ(info_t *info)
{
    for (int i = 0; info->champion[i] != NULL; i++) {
        if (info->champion[i]->said_live == false
        && info->champion[i]->is_alive) {
            info->champion[i]->is_alive = false;
            the_champ_is_dead(info, i);
        }
        info->champion[i]->said_live = false;
    }
}

void is_alive(info_t *info, int y, int i)
{
    if (info->champion[i]->is_alive
            && info->champion[i]->prog_nbr == info->order_execute[y])
                info->champion[i]->pc += which_instruction(info, i);
}

int corewar(info_t *info)
{
    if (NBR_CYCLE % info->cycle->cycle_to_die == 0 && NBR_CYCLE > 0)
        die_champ(info);
    while (info->count_live >= NBR_LIVE
    && info->cycle->cycle_to_die - CYCLE_DELTA > 0) {
        info->cycle->cycle_to_die -= CYCLE_DELTA;
        info->count_live -= NBR_LIVE;
    }
    for (int y = 0; info->order_execute[y]; y++)
        for (int i = 0; info->champion[i] != NULL; i++)
            is_alive(info, y, i);
    return 0;
}
