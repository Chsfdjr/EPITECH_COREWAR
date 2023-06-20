/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** POWERRR second
*/

int my_compute_power_rec(int nb, int p)
{
    long int nb_but_better;

    nb_but_better = nb;
    if (p < 0){
        return 0;
    }
    if (p == 0){
        return 1;
    }
    if (p == 1){
        return nb_but_better;
    }
    nb_but_better *= (my_compute_power_rec(nb, p - 1));
    if (nb_but_better > -2147483648 && nb_but_better < 2147483647){
        return nb_but_better;
    }
    return 0;
}
