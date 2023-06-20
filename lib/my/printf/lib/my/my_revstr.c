/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** task03 day06
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int n = my_strlen(str);
    int i_deb = 0;
    int i_fin = n - 1;
    char prov;

    while (i_deb < n / 2) {
        prov = str[i_deb];
        str[i_deb] = str[i_fin];
        str[i_fin] = prov;
        i_deb += 1;
        i_fin -= 1;
    }
    return str;
}
