/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** free_struct
*/

#include "../../include/corewar_vm.h"

void free_champion(champion_t **champion)
{
    for (int i = 0; champion[i] != NULL ; i++) {
        if (champion[i]->name)
            free(champion[i]->name);
        free(champion[i]->registre);
        free(champion[i]);
    }
    free(champion);
}

void free_struct(info_t *info)
{
    free(info->cycle);
    if (info->champion != NULL)
        free_champion(info->champion);
    if (info->arena != NULL)
        free(info->arena);
    if (info->order_execute != NULL)
        free(info->order_execute);
    free(info);
}
