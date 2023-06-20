/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** init_cycle
*/

#include "../../include/corewar_vm.h"

cycle_t *init_struct_cycle(void)
{
    cycle_t *cycle = malloc(sizeof(cycle_t));
    cycle->count_cycle = 0;
    cycle->cycle_dump = -2;
    cycle->cycle_to_die = CYCLE_TO_DIE;
    return cycle;
}
