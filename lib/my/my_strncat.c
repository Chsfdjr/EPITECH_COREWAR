/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** N cat
*/
int my_strlen(char const *str);
char *my_strncat ( char *dest , char const *src ,int nb)
{
    int i = my_strlen(dest);
    while (src[0] != '\0' && nb != 0) {
        dest[i] = src[0];
        src++;
        i++;
        nb--;
        }
    return (dest);
}
