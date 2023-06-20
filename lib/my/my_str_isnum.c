/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** NUM
*/
int my_str_isnum (char const *str )
{
    while (str[0] != '\0'){
        if (str[0] < '0' || str[0] > '9')
            return 0;
        str++;
    }
    return 1;
}
