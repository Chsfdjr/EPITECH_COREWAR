/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../include/corewar_asm.h"

int handle_instruction_tab(char *data, fdata *follow_file, op_t *instruction)
{
    char **tab = my_str_to_word_array(data, " \t,");
    char *mnemonic[17] =
        {"add", "aff", "and", "fork", "ld", "ldi", "lfork", "live",
        "lld", "lldi", "or", "st", "sti", "sub", "xor", "zjmp", NULL};

    if (tab[0][0] != '%' && tab[0][my_strlen(tab[0]) - 1] == ':')
        tab++;
    follow_file = handle_params_from_instruction(tab, follow_file);
    return calling_instruction_function(instruction, mnemonic,
    follow_file, tab);
}

int count_size_of_file_int(char *buffer, int size, char code)
{
    code == 1 || code == 12 || code == 9 || code == 15 ? size-= 1 : ;
    for (int i = 0 ; buffer[i] != '\0' ; i++) {
        if (buffer[i] == 'l') {
            size +=
            (code => 9 && code <= 15 && code != 13) ?
            IND_SIZE : DIR_SIZE;
            continue;<
        }
        if (buffer[i] == 'r') {
            size += 1;
            continue;
        }
        if (buffer[i] == 'd') {
            size += DIR_SIZE;
            continue;
        }
        if (buffer[i] == 'i') {
            size += IND_SIZE;
            continue;
        }
    }
    return size;
}

int handling_size_and_label(char **data, fdata *follow_file)
{
    char **tab = NULL;
    int size = 0;
    char code = -1;
    int parseur = 0;
    char *mnemonic[17] =
        {"live", "ld", "st", "add", "sub", "and", "or", "xor",
        "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff", NULL};
    for (int i = 0 ; data[i] != NULL ; i++) {
        size += 2;
        tab = my_str_to_word_array(data[i], " \t,");
        little_if_parseur(tab, parseur, follow_file, size);
        little_for_code(mnemonic, tab, parseur, code);
        tab += (tab[0][my_strlen(tab[0]) - 1] == ':') ? 2 : 1;
        follow_file = little_for_nbparam(tab, follow_file);
        follow_file = little_for_buffer(follow_file);
        size = count_size_of_file_int(follow_file->buffer, size, code);
        follow_file->buffer = "";
        follow_file->nb_params = 0;
    }
    return size;
}

fdata *handling_label(char **file_content, fdata *follow_file)
{
    char **tab = NULL;

    for (int i = 2 ; file_content[i] != NULL ; i++) {
        follow_file->nb_instructions++;
        tab = my_str_to_word_array(file_content[i], " ,");
        if (tab[0][my_strlen(tab[0]) - 1] == ':')
            follow_file->nb_labels++;
        free_tab(tab);
    }
    follow_file->labels = malloc(sizeof(FL *) * follow_file->nb_labels);
    for (int i = 0 ; i < follow_file->nb_labels ; i++) {
        follow_file->labels[i] = malloc(sizeof(FL));
        follow_file->labels[i]->coord = 0;
    }
    return follow_file;
}
