/*
** EPITECH PROJECT, 2022
** my_str_isprintable.c
** File description:
** PRINT
*/
int my_str_isprintable (char const *str )
{
    while (str[0] != '\0'){
        if (str[0] < 32 || str[0] > 126) {
            return 0;
        }
        str++;
    }
    return 1;
}
