/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** CASE
*/

char *my_strupcase ( char *str )
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 123 && str[i] > 96) {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return str;

}
