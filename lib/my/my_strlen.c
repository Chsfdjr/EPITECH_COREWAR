/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** len mais en moins bien
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}
