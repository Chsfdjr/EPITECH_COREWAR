/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** corewar
*/

#include "../include/corewar_asm.h"

int close_and_free(char **data, FILE *fd, FILE *fd_cor, int value)
{
    if (fd_cor != NULL)
        fclose(fd_cor);
    if (fd != NULL)
        fclose(fd);
    if (data != NULL)
        free_tab(data);
    return value;
}

int asm_h(void)
{
    char const *filepath = "./asm/asm_h.txt";
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    stream = fopen(filepath, "r");
    if (stream == NULL)
        return -84;
    while ((nread = getline(&line, &len, stream)) != -1) {
        write(1, line, nread);
    }
    free(line);
    fclose(stream);
    return 0;
}

char *convert_file_in_cor(char *file)
{
    char *new_file_name = malloc(sizeof(char) * my_strlen_charc(file, '.') + 4);
    char **tab = NULL;
    int i = 0;

    tab = my_str_to_word_array(file, "/");
    for (i = 0 ; tab[i] != NULL ; i++);
    file = tab[i - 1];
    for (i = 0 ; file[i] != '.' && file[i] != '\0' ; i++)
        new_file_name[i] = file[i];
    new_file_name[i] = '\0';
    return add_to_buffer(new_file_name, ".cor", 2);
}

int asm_openfile(char *filename)
{
    FILE *fd = fopen(filename, "r");
    char **file_content = NULL;
    char *filename_cor;
    FILE *fd_cor = NULL;
    int value = 0;
    if (fd == NULL) {
        write(2, "File doesn't exist\n", 19);
        return close_and_free(file_content, fd, fd_cor, 84);
    }
    filename_cor = convert_file_in_cor(filename);
    fd_cor = fopen(filename_cor, "w");
    if (fd_cor == NULL) {
        write(2, "Error from the creation of", 27);
        write(2, filename_cor, my_strlen(filename_cor));
        write(2, "\n", 1);
        return close_and_free(file_content, fd, fd_cor, 84);
    }
    value = asm_write_file(asm_read_sfile(fd), fd_cor);
    free(filename_cor);
    return close_and_free(file_content, NULL, fd_cor, value);
}

int main(int ac, char **av)
{
    if (ac != 2)
        exit(84);
    else {
        if (my_strcmp(av[1], "-h") == 1)
            return asm_h();
        else
            return asm_openfile(av[1]);
    }
}
