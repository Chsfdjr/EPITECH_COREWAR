/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../../include/corewar_asm.h"

void instruction_lld(op_t *body, fdata *follow_file, char **data)
{
    if (follow_file->nb_params != 2)
        exit(84);
    if (follow_file->buffer[0] != 'd' || (follow_file->buffer[0] != 'i' &&
    follow_file->buffer[1] != 'r'))
        exit(84);
    body = malloc(sizeof(op_t));
    body->code = 13;
    follow_file = count_size_of_file(follow_file, body->code);
}
