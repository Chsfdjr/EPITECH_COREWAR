/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** prime
*/
int my_is_prime(int nb)
{
    if (nb <= 1){
        return 0;
    }
    if (nb == 2){
        return 1;
    }
    int modulo = 2;
    while (nb % modulo != 0){
        if (modulo * modulo > nb){
            return 1;
        }
        modulo++;
    }
    return 0;

}
