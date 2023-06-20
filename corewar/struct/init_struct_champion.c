/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** init_cycle
*/

#include "../../include/corewar_vm.h"

int *init_registre(int nb_champ)
{
    int *registre = malloc(sizeof(int) * (REG_NUMBER));
    registre[0] = nb_champ;
    for (int i = 1; i < REG_NUMBER; i++)
        registre[i] = 2;
    return registre;
}

void read_instruction(int fd, unsigned char *string, int size, int offset)
{
    for (int i = 0; i < offset; i++)
        string++;
    for (int i = 0; i < size; i++) {
        read(fd, string, 1);
        if (offset + 1 == MEM_SIZE) {
            string -= MEM_SIZE - 1;
            offset -= MEM_SIZE - 1;
        } else {
            offset++;
            string++;
        }
    }
}

void create_champ_string(char *av, unsigned char *string, champion_t *champion)
{
    int fd = -1;
    char buffer[COMMENT_LENGTH + 4];
    int size = 0;
    int i;
    fd = open(av, O_RDONLY);
    if (fd > -1) {
        read(fd, buffer, 4);
        read(fd, buffer, PROG_NAME_LENGTH + 4);
        for (i = 0; i < PROG_NAME_LENGTH && buffer[i]; i++);
        champion->name = my_strndup(buffer, i);
        read(fd, &size, sizeof(int));
        size = big_endian_to_little_endian(size);
        read(fd, buffer, COMMENT_LENGTH + 4);
        read_instruction(fd, string, size, champion->mem_pos);
        close (fd);
    }
}

void init_fork(info_t *info, int champ_index, int index_fork, int pos)
{
    info->champion[index_fork] = malloc(sizeof(champion_t));
    info->champion[index_fork]->is_alive = true;
    info->champion[index_fork]->said_live = CHAMP->said_live;
    info->champion[index_fork]->carry = CHAMP->carry;
    info->champion[index_fork]->name = my_strdup(CHAMP->name);
    info->champion[index_fork]->registre = my_intdup(CHAMP->registre);
    info->champion[index_fork]->prog_nbr = CHAMP->prog_nbr;
    info->champion[index_fork]->pc = pos;
    info->champion[index_fork]->nb_cycle_here = 0;
}

champion_t **init_struct_champion(int ac, char **av)
{
    champion_t **champion = malloc(sizeof(champion_t *)
    * (count_champ(ac, av) + 1));
    int champ_index = 0;
    for (int i = 1; i < ac; i++)
        if (my_strncmp_inv(av[i], ".cor", 4) == 0 && is_a_champ(av[i])) {
            champion[champ_index] = malloc(sizeof(champion_t));
            champion[champ_index]->is_alive = true;
            champion[champ_index]->said_live = false;
            champion[champ_index]->carry = true;
            champion[champ_index]->name = NULL;
            MYCHAMP->prog_nbr = (size_champ(av[i]) * (champ_index + 1) * ac);
            MYCHAMP->registre = init_registre(champion[champ_index]->prog_nbr);
            champion[champ_index]->mem_pos
            = (MEM_SIZE / count_champ(ac, av) * champ_index);
            champion[champ_index]->pc = champion[champ_index]->mem_pos;
            champion[champ_index]->nb_cycle_here = 0;
            champ_index++;
    }
    champion[count_champ(ac, av)] = NULL;
    return champion;
}
