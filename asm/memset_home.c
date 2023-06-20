/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** memset_home
*/

#include "../include/corewar_asm.h"

void my_memset(header_t *header, char fill)
{
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        header->prog_name[i] = fill;
    for (int i = 0; i < COMMENT_LENGTH; i++)
        header->comment[i] = fill;
}
