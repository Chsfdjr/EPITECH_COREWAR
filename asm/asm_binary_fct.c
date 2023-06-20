/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../include/corewar_asm.h"

int put_in_big_endian(int little_endian)
{
    int big_endian = 0;
    int big_endian_tab[4];
    big_endian_tab[0] = ((little_endian & 0X000000FF) << 24);
    big_endian_tab[1] = ((little_endian & 0X0000FF00) << 8);
    big_endian_tab[2] = ((little_endian & 0X00FF0000) >> 8);
    big_endian_tab[3] = ((little_endian & 0XFF000000) >> 24);

    big_endian = big_endian_tab[0] | big_endian_tab[1]
    | big_endian_tab[2] | big_endian_tab[3];

    return big_endian;
}

char *handle_condingbyte_2(char type)
{
    if (type == 'r')
        return "01010000";
    if (type == 'i')
        return "11010000";
    if (type == 'd')
        return "10010000";

    return "00000000";
}

char *handle_condingbyte_3(char type)
{
    if (type == 'r')
        return "01010000";
    if (type == 'i')
        return "01110000";

    return "00000000";
}

char *handle_condingbyte_4_2(char type1, char type2)
{
    if (type1 == 'r') {
        if (type2 == 'r')
            return "01010100";
        if (type2 == 'i')
            return "01110100";
        if (type2 == 'd')
            return "01100100";
    }
    if (type1 == 'i') {
        if (type2 == 'i')
            return "11110100";
        if (type2 == 'd')
            return "11100100";
        if (type2 == 'r')
            return "11010100";
    }
    return "00000000";
}

char *handle_condingbyte_4(char type1, char type2)
{
    handle_condingbyte_4_2(type1, type2);
    if (type1 == 'd') {
        if (type2 == 'd')
            return "10100100";
        if (type2 == 'i')
            return "10110100";
        if (type2 == 'r')
            return "10010100";
    }

    return "00000000";
}
