/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** CAPITALISM
*/

char *my_strcapitalize ( char *str )
{
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] < 91 && str[i] > 64) {
            str[i] = str[i] + 32;
        }
        if ((str[i - 1] == '+' || str [i - 1] == '-'
        || str[i - 1] == ' ' || i == 0) && str[i] < 123 && str[i] > 96 ) {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return str;
}
