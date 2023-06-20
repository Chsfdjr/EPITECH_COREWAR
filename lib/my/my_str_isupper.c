/*
** EPITECH PROJECT, 2022
** my_str_isupper.c
** File description:
** UPPER
*/
int my_str_isupper (char const *str )
{
    while (str[0] != '\0'){
        if (str[0] > 90 || str[0] < 65)
            return 0;
        str++;
    }
    return 1;
}
