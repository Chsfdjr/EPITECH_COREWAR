/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../../include/corewar_asm.h"

void instruction_ldi(op_t *body, fdata *follow_file, char **data)
{
    if (follow_file->nb_params != 3)
        exit(84);
    if ((follow_file->buffer[0] != 'l' || follow_file->buffer[0] != 'r')
    && (follow_file->buffer[1] != 'l' || follow_file->buffer[1] != 'r' ) &&
    follow_file->buffer[2] != 'r')
        exit(84);
    body = malloc(sizeof(op_t));
    body->code = 10;
    follow_file = count_size_of_file(follow_file, body->code);
}
