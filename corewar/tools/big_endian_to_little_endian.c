/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** big_endian_to_little_endian
*/

#include "../include/corewar_vm.h"

int big_endian_to_little_endian(int big_endian)
{
    int little_endian = 0;
    int little_endian_tab[3];
    little_endian_tab[0] = ((big_endian & 0X000000FF) << 24);
    little_endian_tab[1] = ((big_endian & 0X0000FF00) << 8);
    little_endian_tab[2] = ((big_endian & 0X00FF0000) >> 8);
    little_endian_tab[3] = ((big_endian & 0XFF000000) >> 24);

    little_endian = little_endian_tab[0] | little_endian_tab[1]
    | little_endian_tab[2] | little_endian_tab[3];

    return little_endian;
}
