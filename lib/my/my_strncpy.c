/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** copy any char
*/
char my_strlen(char const *str);
char *my_strncpy ( char *dest , char const *src , int n)
{
    int i;
    for (i = 0; i < n ;i++){
        dest[i] = src[i];
    }
    if (n > my_strlen(src))
        dest[n] = '\0';
    return dest;
}
