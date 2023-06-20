/*
** EPITECH PROJECT, 2023
** Core War
** File description:
** binary
*/

#include "../include/corewar_asm.h"

char *handle_condingbyte_5_2(char type1, char type2)
{
    if (type1 == 'r') {
        if (type2 == 'r')
            return "01010100";
        if (type2 == 'i')
            return "01011100";
        if (type2 == 'd' || type2 == 'l')
            return "01011000";
    }
    if (type1 == 'i') {
        if (type2 == 'i')
            return "01111100";
        if (type2 == 'd' || type2 == 'l')
            return "01111000";
        if (type2 == 'r')
            return "01110100";
    }
    return "00000000";
}

char *handle_condingbyte_5(char type1, char type2)
{
    handle_condingbyte_5_2(type1, type2);
    if (type1 == 'd' || type1 == 'l') {
        if (type2 == 'i')
            return "01101100";
        if (type2 == 'd')
            return "01101000";
        if (type2 == 'r')
            return "01100100";
    }
    return "00000000";
}

char *binary_to_decimal(char coding_byte[MAX_ARGS_NUMBER])
{
    int decimal = 0;
    for (int i = 0; coding_byte[i] != '\0'; i++) {
        decimal = decimal * 2 + (coding_byte[i] - '0');
    }
    int decimal_length = 1;
    int temp = decimal;
    while (temp /= 10)
        decimal_length++;
    char* result = malloc(sizeof(char) * (decimal_length + 1));
    int index = decimal_length - 1;
    while (decimal != 0) {
        result[index] = decimal % 10 + '0';
        decimal /= 10;
        index--;
    }
    result[decimal_length] = '\0';

    return result;
}

args_type_t *handle_condingbyte(char type[MAX_ARGS_NUMBER],
int params)
{
    char *coding_byte = "00000000";

    if (type[1] == 'r' && params == 2)
        coding_byte = handle_condingbyte_2(type[0]);
    if (type[0] == 'r' && params == 2)
        coding_byte = handle_condingbyte_3(type[1]);
    if (type[0] == 'r' && type[1] == 'r' && type[2] == 'r' && params == 3)
        coding_byte = "01010100";
    if (params == 3 && type[2] == 'r')
        coding_byte = handle_condingbyte_4(type[0], type[1]);
    if (params == 3 && type[0] == 'r')
        coding_byte = handle_condingbyte_5(type[1], type[2]);
    if (params == 1 && type[0] == 'r')
        coding_byte = "01000000";

    return coding_byte;
}
