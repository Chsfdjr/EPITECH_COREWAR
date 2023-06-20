/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** cat
*/

int my_strlen(char *str);
char *my_strcat ( char *dest , char const *src )
{
    int i = my_strlen(dest);
    while (src[0] != '\0') {
        dest[i] = src[0];
        src++;
        i++;
        }
    dest[i] = '\0';
    return (dest);
}
