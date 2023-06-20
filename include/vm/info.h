/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** info
*/

#include "cycle.h"
#include "champion.h"

#ifndef COREWAR_INFO_VM_H
    #define COREWAR_INFO_VM_H

typedef struct info_s {
    cycle_t *cycle;
    champion_t **champion;
    unsigned char *arena;
    int nbr_champ_alive;
    int nbr_last_champ_alive;
    int count_live;
    int *order_execute;
} info_t;

#endif
