/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** task07
*/

void my_putchar(char c);

int find_div(long nb)
{
    int pow = 0;

    if (nb < 0) {
        nb *= -1;
    }
    while (nb >= 1) {
        nb /= 10;
        pow += 1;
    }
    return pow;
}

void cas_xtrm(long nb)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(long nb)
{
    long n_prov;
    int div = 1;
    int compteur;

    if (nb == -2147483648) {
        cas_xtrm(nb);
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    compteur = find_div(nb);
    for (compteur; compteur > 1; compteur -= 1)
        div *= 10;
    for (div; div > 0; div /= 10) {
        my_putchar(48 + nb / div);
        nb = nb % div;
    }
    return 0;
}
