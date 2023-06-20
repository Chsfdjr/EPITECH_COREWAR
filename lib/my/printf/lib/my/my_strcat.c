/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** task02 day07
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    while (dest[i] != '\0')
        i ++;
    for (int j = 0; j < my_strlen(src); j++)
        dest[i + j] = src[j];
    return dest;
}
