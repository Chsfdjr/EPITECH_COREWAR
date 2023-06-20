/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** put nb
*/
void my_putchar(char c);
int my_putstr(char const *str);

void my_print_int(int nb)
{
    if (nb > 9)
        my_print_int(nb / 10);
    my_putchar((nb % 10) + 48);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648){
        my_putstr("-2147483648");
        return 0;
    }
    if (nb > 0){
        my_print_int(nb);
    } else if (nb < 0) {
        my_putchar(45);
        my_print_int(-(nb));
    } else {
        my_putchar(48);
    }
    return 0;
}
