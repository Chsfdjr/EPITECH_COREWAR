/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** task02 day6 copy n
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int len_source = my_strlen(src);
    int len_dest = n;
    int test = 0;

    if (n > len_source) {
        n = len_source;
        test = 1;
    }
    for (int i = 0; i < n; i ++)
        dest[i] = src[i];
    if (test == 1)
        dest[n] = '\0';
    return dest;
}
