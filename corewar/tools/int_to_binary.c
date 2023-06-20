/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** int_to_binary
*/

#include "../include/corewar_vm.h"

int *int_to_bin(int num)
{
    int *bin = malloc(sizeof(int) * 8);
    for (int i = 0; i < 8; i++)
        bin[i] = 0;
    for (int i = 7; num > 0; i--) {
        bin[i] = num % 2;
        num /= 2;
    }
    return bin;
}
