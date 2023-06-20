/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** task04 d5
*/

int my_compute_power_it(int nb, int c);

int my_compute_power_rec(int nb, int c)
{
    int res;
    long temp = nb;

    if (c < 0) {
        return 0;
    }
    if (c == 0) {
        return 1;
    }
    temp = temp * my_compute_power_rec(temp, c - 1);
    if (temp <= -2147483648 || temp >= 2147483647) {
        return 0;
    }
    res = temp;
    return res;
}
