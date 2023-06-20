/*
** EPITECH PROJECT, 2022
** pos or neg
** File description:
** n or p
*/
void my_putchar(char c);
int my_isneg(int n)
{
    if (n < 0){my_putchar(78);
    } else {
        my_putchar(80);
    }
    return 0;
}
