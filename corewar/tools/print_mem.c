/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** print_mem
*/

#include "../include/corewar_vm.h"

int print_mem(info_t *info)
{
    int var = 0;
    for (int j = 0; j < MEM_SIZE; j++) {
        if ((int) info->arena[j] == 0)
            my_printf("00");
        else
            my_printf("%.2X", 0x000000FF & (int) info->arena[j]);
        if (var == 31) {
            my_printf("\n");
            var = 0;
        } else
            var++;
    }
    return 0;
}
