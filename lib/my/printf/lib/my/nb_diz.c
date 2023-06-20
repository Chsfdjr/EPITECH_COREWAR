/*
** EPITECH PROJECT, 2022
** nb_diz
** File description:
** nb diz
*/

int nb_diz(int nbr)
{
    int a = 2;
    for (; nbr >= 100;a++)
        nbr /= 10;
    return a;
}
