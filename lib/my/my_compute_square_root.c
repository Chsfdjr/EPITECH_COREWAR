/*
** EPITECH PROJECT, 2022
** square_root
** File description:
** damn
*/
int my_compute_square_root(int nb)
{
    int temp = 0;

    if (nb <= 0){
        return 0;
    }
    if (nb == 1){
        return 1;
    }
    while (temp * temp < nb){
        temp++;
    }
    if (temp * temp == nb){
        return temp;
    } else {
        return 0;
    }
}
