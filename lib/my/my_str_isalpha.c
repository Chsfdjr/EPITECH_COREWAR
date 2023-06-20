/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** alpha string
*/
int my_str_isalpha (char const *str )
{
    while (str[0] != '\0'){
        if ((str[0] < 97 && str[0] > 90 ) || (str[0] < 65 || str[0] > 122))
            return 0;
        str++;
    }
    return 1;
}
