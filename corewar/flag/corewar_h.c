/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** corewar_h
*/

#include "../../include/corewar_vm.h"

int corewar_h(int ac, char **av, info_t *info)
{
    char const *filepath = "./corewar/corewar_h.txt";
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    if (ac == 2 && my_strcmp(av[1], "-h") == 1) {
        stream = fopen(filepath, "r");
        if (stream == NULL)
            return -84;
        while ((nread = getline(&line, &len, stream)) != -1) {
            write(1, line, nread);
        }
        free(line);
        fclose(stream);
        exit_and_free(info, 0);
    }
    return 0;
}
