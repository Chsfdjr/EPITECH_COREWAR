/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../include/corewar_asm.h"

void error_from_header(char **data)
{
    if (my_strncmp(data[0], ".name", my_strlen(".name")) != 0 ||
    my_strncmp(data[1], ".comment", my_strlen(".comment")) != 0 ) {
        write(2, "name or comment not define\n", 27);
        free_tab(data);
        exit(84);
    }
    return;
}

char *remove_comment(char *buf)
{
    int i = 0;

    while (buf[i] != '\0') {
        if (buf[i] == '#') {
            buf[i] = '\n';
            buf[i + 1] = '\0';
            return buf;
        } else
            i++;
    }
    return buf;
}

char *remove_first_space(char *buf)
{
    while (*buf == ' ' || *buf == '\t')
        buf++;
    return buf;
}

char **asm_read_sfile(FILE *fd)
{
    char **tab = NULL;
    char *line = NULL;
    char *buf = "";
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, fd)) != -1) {
        line = remove_first_space(line);
        line = remove_comment(line);
        buf = add_to_buffer(buf, line, 2);
    }
    tab = my_str_to_word_array(buf, "\n");
    free(buf);
    error_from_header(tab);
    fclose(fd);
    return tab;
}
