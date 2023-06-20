/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** champion
*/

#ifndef COREWAR_CHAMPION_VM_H
    #define COREWAR_CHAMPION_VM_H

typedef struct champion_s {
    bool is_alive;
    bool said_live;
    bool carry;
    char *name;
    int *registre;
    int prog_nbr;
    int mem_pos;
    int pc;
    int nb_cycle_here;
} champion_t;

#endif
