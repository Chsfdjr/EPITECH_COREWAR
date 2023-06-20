/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../../include/corewar_asm.h"

void instruction_lfork(op_t *body, fdata *follow_file, char **data)
{
    if (follow_file->nb_params != 1)
        exit(84);
    if (follow_file->buffer[0] != 'l')
        exit(84);
    body = malloc(sizeof(op_t));
    body->code = 15;
    follow_file = count_size_of_file(follow_file, body->code);
}
