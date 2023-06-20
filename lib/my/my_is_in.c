/*
** EPITECH PROJECT, 2022
** my_get_nbr
** File description:
** is in
*/

int is_in(char *dest, char src)
{
    int i = 0;
    while (dest[i]) {
        if (dest[i] == src)
            return 1;
        i++;
    }
    return 0;
}
