/*
** EPITECH PROJECT, 2023
** asm_handle_fct_2
** File description:
** corewar
*/

#include "../include/corewar_asm.h"

fdata *little_for_nbparam(char **tab, fdata *f)
{
    for (int i = 0; tab[i] != NULL; i++) {
        f->buffer = h_p_f_instruction_conditions(i, tab, f->buffer);
        f->nb_params++;
    }
    return f;
}

fdata *little_if_parseur(char **tab, int parseur, fdata *follow_file, int size)
{
    int lb = 0;

    if (tab[parseur][my_strlen(tab[parseur]) - 1] == ':') {
        follow_file->labels[lb]->buffer =
            malloc(sizeof(char) * my_strlen(tab[0]));
        follow_file->labels[lb]->buffer = tab[0];
        follow_file->labels[lb]->coord = size;
        lb++;
        parseur++;
    }
    return follow_file;
}

fdata *little_for_buffer(fdata *f)
{
    for ( ; f->nb_params != 4 ; f->nb_params++)
        f->buffer = add_to_buffer(f->buffer, "o", 2);

    return f;
}

char little_for_code(char *mnemonic[17], char **tab, int parseur, char code)
{
    for (int i = 0 ; mnemonic[i] != NULL && code == -1; i++)
        code = (my_strcmp(mnemonic[i], tab[parseur]) == 0) ? i : code;
    return code;
}
