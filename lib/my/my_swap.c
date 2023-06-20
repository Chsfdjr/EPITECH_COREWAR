/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** swap 2 int
*/

void my_swap( int *a , int *b )
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
