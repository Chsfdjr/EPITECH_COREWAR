/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../include/corewar_vm.h"

void exit_and_free(info_t *info, int exit_value)
{
    free_struct(info);
    exit(exit_value);
}

void print_winner(info_t *info)
{
    for (int champ_index = 0; CHAMP != NULL; champ_index++)
        if (CHAMP->is_alive) {
            my_printf("The player %d(%s) has won.\n",
            CHAMP->prog_nbr, CHAMP->name);
            return;
        }
    my_printf("The player %d(%s) has won.\n",
        info->champion[info->nbr_last_champ_alive]->prog_nbr,
        info->champion[info->nbr_last_champ_alive]->name);
}

int main(int ac, char **av)
{
    info_t *info = init_struct_info(ac, av);
    int return_value = 0;

    for (NBR_CYCLE = 0; info->nbr_champ_alive > 1 && (NBR_CYCLE_DUMP == -2
    || NBR_CYCLE <= NBR_CYCLE_DUMP); NBR_CYCLE++)
        corewar(info);
    NBR_CYCLE--;
    if (count_champ(ac, av) == 0) {
        my_printf("Need Champion for fight\n");
        return_value = 84;
    } else if (NBR_CYCLE == NBR_CYCLE_DUMP)
        print_mem(info);
    else
        print_winner(info);
    free_struct(info);
    return return_value;
}
