/*
** EPITECH PROJECT, 2022
** my_show_str
** File description:
** show
*/
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_str_isprintable(char const *str);
int my_put_hexadecimal(int nb);
void my_putchar_nonprintable(char str)
{
    if (str < 32 || str > 126) {
        my_putchar('\\');
        if (str < 16)
            my_putchar('0');
        my_put_hexadecimal(str);
    } else {
        my_putchar(str);
    }
}

int my_showstr(char const *str)
{
    int i ;
    if (my_str_isprintable(str))
        my_putstr(str);
    else {
        while (str[i]) {
            my_putchar_nonprintable(str[i]);
            i++;
        }
    }
    return 0;
}
