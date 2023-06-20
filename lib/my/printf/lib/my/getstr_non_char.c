/*
** EPITECH PROJECT, 2022
** getstr_non_char
** File description:
** get str without char at the end
*/
int my_strlen(char *str);

int getstr_non_char(char *nb, char not)
{
    int index = my_strlen(nb) - 1;
    while (nb[index] == not)
        index -= 1;
    return index + 1;
}
