/*
** EPITECH PROJECT, 2023
** B-PSU-200-MLH-2-1-minishell1-sacha.ramstein
** File description:
** my_input
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include <errno.h>

int my_strcmp (char const *s1, char const *s2);

char *my_input(char *question, char **env)
{
    if (isatty(0))
        my_printf("%s",question);
    int size;
    char *buffer = malloc(sizeof(char) * 32000);
    size = read(0, buffer, 31999);
    if (size == 1 || size == 0) {
        for (int i = 0; env[i]; i++)
            my_printf("%s\n", env[i]);
        return NULL;
    }
    if (size > 1)
        buffer[size - 1] = '\0';
    return buffer;
}
