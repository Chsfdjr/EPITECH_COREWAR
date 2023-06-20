/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** corewar_n
*/

#include "../../include/corewar_vm.h"
int count_nb_champ_with_nbr(info_t *info, int nbr)
{
    int count = 0;

    for (int champ_index = 0; CHAMP != NULL; champ_index++)
        if (CHAMP->prog_nbr == nbr)
            count++;
    return count;

}

int change_double_nb_champ(info_t *info, int nbr)
{
    int champ_index;

    for (int count = count_nb_champ_with_nbr(info, nbr); count > 1; count --) {
        for (champ_index = 0; CHAMP != NULL
        && CHAMP->prog_nbr != nbr; champ_index++);
        CHAMP->prog_nbr = nbr * count;
        CHAMP->registre[0] = CHAMP->prog_nbr;
    }
    return 1;
}

int corewar_n(int ac, char **av, info_t *info)
{
    int prog_nbr = -1;
    int champ_index = 0;

    for (int i = 1; i < ac ; i++) {
        if (my_strcmp(av[i], "-n") == 1
        && ac > i + 1 && my_str_isnum(av[i + 1]))
            prog_nbr = my_getnbr(av[i + 1]);
        if (is_a_champ(av[i]) && prog_nbr != -1 && prog_nbr != 0) {
            info->champion[champ_index]->prog_nbr = prog_nbr;
            CHAMP->registre[0] = prog_nbr;
            change_double_nb_champ(info, prog_nbr);
            prog_nbr = -1;
        }
        if (is_a_champ(av[i]))
            champ_index++;
    }
    return 1;
}
