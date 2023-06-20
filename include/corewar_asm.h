/*
** EPITECH PROJECT, 2023
** bin
** File description:
** projet
*/

#include "../include/op.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#ifndef COREWAR_ASM_H
    #define COREWAR_ASM_H

typedef struct follow_label {
    char *buffer;
    int coord;
} FL;

typedef struct size_of_file {
    int size;
    char *buffer;
    int nb_params;
    int nb_instructions;
    int nb_labels;
    int checkpoint_size;
    FL **labels;
    FILE *fd;
} fdata;

int main(int ac, char **av);
char **asm_read_sfile(FILE *fd);
int asm_write_file(char **file_content, FILE *fd);
void instruction_add(op_t *body, fdata *follow_file, char **data);
void instruction_aff(op_t *body, fdata *follow_file, char **data);
void instruction_and(op_t *body, fdata *follow_file, char **data);
void instruction_fork(op_t *body, fdata *follow_file, char **data);
void instruction_ld(op_t *body, fdata *follow_file, char **data);
void instruction_ldi(op_t *body, fdata *follow_file, char **data);
void instruction_lfork(op_t *body, fdata *follow_file, char **data);
void instruction_live(op_t *body, fdata *follow_file, char **data);
void instruction_lld(op_t *body, fdata *follow_file, char **data);
void instruction_lldi(op_t *body, fdata *follow_file, char **data);
void instruction_or(op_t *body, fdata *follow_file, char **data);
void instruction_st(op_t *body, fdata *follow_file, char **data);
void instruction_sti(op_t *body, fdata *follow_file, char **data);
void instruction_sub(op_t *body, fdata *follow_file, char **data);
void instruction_xor(op_t *body, fdata *follow_file, char **data);
void instruction_zjmp(op_t *body, fdata *follow_file, char **data);
void count_size_header(header_t *header, fdata *f_f);
fdata *count_size_of_file(fdata *follow_file, char code);
fdata *fill_struct_fdata(fdata *f_f, FILE *fd);
fdata *parser_file_content(header_t *header, char **file_content, fdata *f_f);
void logs(char **tab);
header_t *fill_header_without_size(header_t *fill, char **file_content);
fdata *handle_params_from_instruction(char **data, fdata *f_f);
int handle_instruction_tab(char *data, fdata *follow_file, op_t *instruction);
int close_and_free(char **data, FILE *fd, FILE *fd_cor, int value);
char *handle_condingbyte_5_2(char type1, char type2);
char *handle_condingbyte_5(char type1, char type2);
char *binary_to_decimal(char coding_byte[MAX_ARGS_NUMBER]);
args_type_t *handle_condingbyte(char type[MAX_ARGS_NUMBER],
int params);
char *handle_condingbyte_2(char type);
char *handle_condingbyte_3(char type);
char *handle_condingbyte_4_2(char type1, char type2);
char *handle_condingbyte_4(char type1, char type2);
void free_tab(char **tab);
fdata *handling_label(char **file_content, fdata *follow_file);
int handling_size_and_label(char **data, fdata *follow_file);
int calling_instruction_function
(op_t *instruction, char *mnemonic[17], fdata *follow_file, char **tab);
char *h_p_f_instruction_conditions(int i, char **data, char *buffer);
int put_in_big_endian(int little_endian);
fdata *little_for_nbparam(char **tab, fdata *f);
fdata *little_if_parseur(char **tab, int parseur, fdata *follow_file,
int size);
fdata *little_for_buffer(fdata *f);
char little_for_code(char *mnemonic[17], char **tab, int parseur, char code);
void my_memset(header_t *header, char fill);

#endif
