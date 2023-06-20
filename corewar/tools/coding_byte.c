/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** coding_byte
*/

#include "../include/corewar_vm.h"

int free_bin(int *bin, int return_value)
{
    free(bin);
    return return_value;
}

int what_type_is_it(int charette, int num_param)
{
    charette = 0x000000FF & charette;
    int *bin = int_to_bin(charette);
    num_param = (num_param - 1) * 2;
    if (bin[num_param] == 0 && bin[num_param + 1] == 1)
        return free_bin(bin,IS_REG);
    if (bin[num_param] == 1 && bin[num_param + 1] == 0)
        return free_bin(bin, IS_DIR);
    if (bin[num_param] == 1 && bin[num_param + 1] == 1)
        return free_bin(bin, IS_INDIR);
    return free_bin(bin, IS_OTHER);
}

int what_size_is_it(int charette, int num_param, char previous)
{
    int num = what_type_is_it(charette, num_param);
    if (num == 0)
        return 1;
    if (num == 1 && previous >= 9 && previous <= 15 && previous != 13)
        return IND_SIZE;
    if (num == 1)
        return DIR_SIZE;
    if (num == 2)
        return IND_SIZE;
    return 0;
}
