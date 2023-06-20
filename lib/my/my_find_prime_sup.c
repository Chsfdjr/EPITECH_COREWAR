/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** find
*/

int my_is_prime(int nb);
int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb)) {
        return nb;
    }
    return my_find_prime_sup(nb + 1);
}
