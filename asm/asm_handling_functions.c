/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../include/corewar_asm.h"

char *h_p_f_instruction_conditions(int i, char **data, char *buffer)
{
    if (data[i][0] == '%' && data[i][1] == ':') {
        buffer = add_to_buffer(buffer, "l", 2);
        return buffer;
    }
    if (data[i][0] == 'r') {
        buffer = add_to_buffer(buffer, "r", 2);
        return buffer;
    }
    if (data[i][0] == '%') {
        buffer = add_to_buffer(buffer, "d", 2);
        return buffer;
    } else {
        buffer = add_to_buffer(buffer, "i", 2);
        return buffer;
    }
    return buffer;
}

fdata *handle_params_from_instruction(char **data, fdata *f_f)
{
    int nb_params = 0;
    char *buffer = "";

    for (int i = 1 ; data[i] != NULL ; i++) {
        buffer = h_p_f_instruction_conditions(i, data, buffer);
        nb_params++;
    }
    f_f->nb_params = nb_params;
    for (nb_params = nb_params ; nb_params != 4 ; nb_params++)
        buffer = add_to_buffer(buffer, "o", 2);
    f_f->buffer = buffer;
    return f_f;
}

int calling_instruction_function
(op_t *instruction, char *mnemonic[17], fdata *follow_file, char **tab)
{
    void (*tab_fct[17]) (op_t *, fdata *, char **) =
        {instruction_add, instruction_aff, instruction_and, instruction_fork,
        instruction_ld, instruction_ldi, instruction_lfork, instruction_live,
        instruction_lld, instruction_lldi, instruction_or, instruction_st,
        instruction_sti, instruction_st, instruction_sub,
        instruction_xor, instruction_zjmp};

    for (int i = 0 ; i < 17 ; i++) {
        if (i > 15) {
            write(2, "bad instruction\n", 16);
            free_tab(tab);
            exit(84);
        }
        if (my_strcmp(tab[0], mnemonic[i]) == 1) {
            tab++;
            tab_fct[i](instruction, follow_file, tab);
            break;
        }
    }
    return 0;
}
