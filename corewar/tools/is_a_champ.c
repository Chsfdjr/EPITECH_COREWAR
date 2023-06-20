/*
** EPITECH PROJECT, 2023
** B-CPE-200-MLH-2-1-corewar-sacha.ramstein
** File description:
** is_a_champ
*/

#include "../include/corewar_vm.h"

bool is_a_champ(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    int num = 0;
    if (fd > -1) {
        if (read(fd, &num, sizeof(int)) < 0) {
            close(fd);
            return false;
        }
        close(fd);
        return num == big_endian_to_little_endian(COREWAR_EXEC_MAGIC);
    }
    return false;
}

int size_champ(char *av)
{
    int fd = -1;
    char buffer[COMMENT_LENGTH + 4];
    int size = 0;
    fd = open(av, O_RDONLY);
    if (fd > -1) {
        read(fd, buffer, 4);
        read(fd, buffer, PROG_NAME_LENGTH + 4);
        read(fd, &size, sizeof(int));
        return big_endian_to_little_endian(size);
    }
    return 0;

}
