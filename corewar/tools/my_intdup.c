/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** my_intdup
*/

#include "../include/corewar_vm.h"

int *my_intdup(int *src)
{
    int *int_tab = malloc(sizeof(int) * (REG_NUMBER));

    for (int i = 0; i < REG_NUMBER ; i ++)
        int_tab[i] = src[i];
    return int_tab;
}
