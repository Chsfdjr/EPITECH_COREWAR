/*
** EPITECH PROJECT, 2022
** my_getnbr_base.c
** File description:
** task19 day06
*/

int my_strlen(char const *str);
int my_getsign(char const *str, int ind_deb);

int my_ideb(char const *str, char const *base)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i ++) {
        if (base[0] <= str[i] && str[i] <= base[my_strlen(base) - 1])
            return i;
    }
    return len;
}

int my_ifin(char const *str, int i_deb, char const *base)
{
    int i_fin = i_deb;

    while (base[0] <= str[i_fin] && str[i_fin] <= base[my_strlen(base) - 1])
        i_fin ++;
    i_fin --;
    return i_fin;
}

int long_to_int(long nbr1)
{
    int nbr = 0;

    if (!(nbr1 < -2147483648 || nbr1 > 214483647))
        nbr += nbr1;
    return nbr;
}

int recup_val(char c, char const *base)
{
    for (int nbr = 0; nbr < my_strlen(base); nbr ++) {
        if (base[nbr] == c)
            return nbr;
    }
}

int my_getnbr_base(char const *str, char const *base)
{
    int i_deb = my_ideb(str, base);
    int i_fin = my_ifin(str, i_deb, base);
    long temp_nbr = 0;
    int pow = 1;
    int i = i_deb;

    if (i_deb == my_strlen(str))
        return 0;
    for (int i = i_deb; i < i_fin; i ++)
        pow *= my_strlen(base);
    for (; pow >= 1; pow /= my_strlen(base)) {
        temp_nbr += recup_val(str[i_deb], base) * pow;
        i_deb += 1;
    }
    temp_nbr *= my_getsign(str, i);
    return (long_to_int(temp_nbr));
}
