/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../include/corewar_asm.h"

fdata *count_size_of_file(fdata *follow_file, char code)
{
    if (code )
    for (int i = 0 ; follow_file->buffer[i] != '\0' ; i++) {
        if (follow_file->buffer[i] == 'l') {
            follow_file->size +=
            (code => 9 && code <= 15 && code != 13) ? IND_SIZE : DIR_SIZE;
            follow_file->checkpoint_size = follow_file->size;
        }
        if (follow_file->buffer[i] == 'r') {
            follow_file->size += 1;
        }
        if (follow_file->buffer[i] == 'd') {
            follow_file->size += DIR_SIZE;
        }
        if (follow_file->buffer[i] == 'i') {
            follow_file->size += IND_SIZE;
        }
    }
    return follow_file;
}

fdata *fill_struct_fdata(fdata *f_f, FILE *fd)
{
    f_f = malloc(sizeof(fdata));
    f_f->size = 0;
    f_f->buffer = malloc(sizeof(char) * 4 + 1);
    f_f->nb_params = 0;
    f_f->nb_labels = 0;
    f_f->checkpoint_size = 0;
    f_f->fd = fd;
    f_f->nb_instructions = 0;
    return f_f;
}

header_t *fill_header_without_size(header_t *fill, char **file_content)
{
    int len_name = my_strlen(file_content[0]);
    int len_comment = my_strlen(file_content[1]);
    int e = 0;

    fill = malloc(sizeof(header_t));
    my_memset(fill, 0);
    fill->magic = put_in_big_endian(COREWAR_EXEC_MAGIC);
    for (int i = 7 ; i < len_name - 1 ; i++) {
        fill->prog_name[e] = file_content[0][i];
        e++;
    }
    fill->prog_name[e] = '\0';
    e = 0;
    for (int i = 10 ; i < len_comment - 1 ; i++) {
        fill->comment[e] = file_content[1][i];
        e++;
    }
    fill->comment[e] = '\0';
    return fill;
}

int asm_write_file(char **file_content, FILE *fd)
{
    int parseur = 0;
    fdata *follow_file = NULL;
    header_t *header_data = NULL;
    op_t **all_instructions;

    follow_file = fill_struct_fdata(follow_file, fd);
    header_data = fill_header_without_size(header_data, file_content);
    follow_file = handling_label(file_content, follow_file);
    header_data->prog_size = put_in_big_endian(
    handling_size_and_label(file_content + 2, follow_file));
    fwrite(header_data, sizeof(header_t), 1, fd);
    all_instructions = malloc(sizeof(op_t*) * follow_file->nb_instructions);
    for (int i = 2 ; follow_file->nb_instructions + 2 > i ; i++) {
        if (handle_instruction_tab
            (file_content[i], follow_file, all_instructions[parseur]) == 84)
            exit(84);
        parseur++;
    }
    return 0;
}
