/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** LOWER
*/
int my_str_islower(char const *str )
{
    while (str[0] != '\0'){
        if ((str[0] < 97 || str[0] > 122)) {
            return 0;
        }
        str++ ;
    }
    return 1;
}
