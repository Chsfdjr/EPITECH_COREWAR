/*
** EPITECH PROJECT, 2023
** bin
** File description:
** projet
*/

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
#include "op.h"
#include "vm/info.h"
#include "vm/params.h"

#ifndef COREWAR_VM_H
    #define COREWAR_VM_H
    #define NBR_CYCLE_DUMP info->cycle->cycle_dump
    #define NBR_CYCLE info->cycle->count_cycle
    #define CHAMP info->champion[champ_index]
    #define MYCHAMP champion[champ_index]
    #define REGISTER_X(x) CHAMP->registre[get_register_index(info, CHAMP->pc,\
    champ_index, x)]
    #define IS_REG 0
    #define IS_DIR 1
    #define IS_INDIR 2
    #define IS_OTHER -1

int main(int ac, char **av);
void debug_arena(int n, info_t *info, int champ_index);

// Flag
int corewar_flag(int ac, char **av, info_t *info);
int corewar_h(int ac, char **av, info_t *info);
int corewar_dump(int ac, char **av, info_t *info, int index);
int corewar_champion_flag(int ac, char **av, info_t *info);
int corewar_n(int ac, char **av, info_t *info);
int corewar_a(int ac, char **av, info_t *info);

// Init_struct
info_t *init_struct_info(int ac, char **av);
cycle_t *init_struct_cycle(void);
champion_t **init_struct_champion(int ac, char **av);
void init_arena(info_t *info, int ac, char **av);
void create_champ_string(char *av, unsigned char *string, champion_t *champion);

// Free struct
void free_struct(info_t *info);

// Exit
void exit_and_free(info_t *info, int exit_value);

// Fonction tools
int my_strncmp_inv(char const *s1, char const *s2, int n);
int count_champ(int ac, char ** av);
int print_mem(info_t *info);
int *int_to_bin(int num);
int big_endian_to_little_endian(int big_endian);
bool is_a_champ(char *file_path);
char *my_strndup ( char const *src, int n);
int what_type_is_it(int charette, int num_param);
int what_size_is_it(int charette, int num_param, char previous);
params_t *get_params(info_t *info, int index_arena, int champ_index);
int get_offset(info_t *info, int index_arena, int champ_index);
int get_register_index(info_t *info, int index_arena, int champ_index, \
int nb_param);
int return_int_from_bytes(info_t *info, int index_arena,
int params, int nb_bytes);
int *my_intdup(int *src);
int size_champ(char *av);

// Fonction Corewar
int corewar(info_t *info);

// Fonction Champiom

// Fonction Instruction
int live(info_t *info, int champ_index);
int ld_instruction(info_t *info, int champ_index);
int st_instruction(info_t *info, int champ_index);
int add(info_t *info, int champ_index);
int sub(info_t *info, int champ_index);
int and_instruction(info_t *info, int champ_index);
int or_instruction(info_t *info, int champ_index);
int xor_instruction(info_t *info, int champ_index);
int zjump(info_t *info, int champ_index);
int ldi(info_t *info, int champ_index);
int sti(info_t *info, int champ_index);
int fork_instruction(info_t *info, int champ_index);
void init_fork(info_t *info, int champ_index, int index_fork, int pos);
int lld(info_t *info, int champ_index);
int lldi(info_t *info, int champ_index);
int lfork(info_t *info, int champ_index);
int aff(info_t *info, int champ_index);
int add_instru(info_t *info, int champ_index);

#endif
