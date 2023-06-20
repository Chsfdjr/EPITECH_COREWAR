/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../include/corewar_asm.h"

void free_tab(char **tab)
{
    for (int i = 0 ; tab[i] != NULL ; i++)
        free(tab[i]);
    free(tab);
}
