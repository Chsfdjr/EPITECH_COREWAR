/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** init_struct
*/

#include "../../include/corewar_vm.h"

void swap_order_execute(info_t *info, int y)
{
    int backup = 0;
    if (info->order_execute[y] > info->order_execute[y + 1]) {
        backup = info->order_execute[y];
        info->order_execute[y] = info->order_execute[y + 1];
        info->order_execute[y + 1] = backup;
    }

}

void sort_order_exec(int ac, char **av, info_t *info)
{
    for (int i = 0; i < count_champ(ac, av) * 3; i++)
        for (int y = 0; y < count_champ(ac, av) - 1; y++)
            swap_order_execute(info, y);
}

info_t *init_struct_info(int ac, char **av)
{
    info_t *info = malloc(sizeof(info_t));
    int index_order = 0;
    info->cycle = init_struct_cycle();
    info->champion = init_struct_champion(ac, av);
    info->arena = NULL;
    info->order_execute = NULL;
    corewar_flag(ac, av, info);
    init_arena(info, ac, av);
    info->nbr_champ_alive = count_champ(ac, av);
    info->nbr_last_champ_alive = 0;
    info->order_execute = malloc(sizeof(int) * (count_champ(ac, av) + 1));
    for (int i = 0; info->champion[i] != NULL; i++) {
        info->order_execute[index_order] = info->champion[i]->prog_nbr;
        index_order++;
    }
    sort_order_exec(ac, av, info);
    info->order_execute[count_champ(ac, av)] = 0;
    info->count_live = 0;
    return info;
}
