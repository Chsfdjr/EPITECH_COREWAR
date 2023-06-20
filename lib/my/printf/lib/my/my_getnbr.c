/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** task05
*/

int my_strlen(char const *str);
int my_getsign(char const *str, int ind_deb);

int my_ind_deb(char const *str)
{
    int len = my_strlen(str);
    int index = 0;

    for (; index < len; index ++) {
        if ('0' <= str[index] && str[index] <= '9') {
            return (index);
        }
    }
    return (len);
}

int my_ind_fin(char const *str, int ind_deb)
{
    int ind_fin;

    ind_fin = ind_deb;
    while ('0' <= str[ind_fin] && str[ind_fin] <= '9') {
        ind_fin ++;
    }
    ind_fin --;
    return (ind_fin);
}

int long_into_int(long nbr1)
{
    int nbr = 0;

    if (nbr1 < -2147483648 || nbr1 > 2147483647) {
        nbr = 0;
    } else {
        nbr += nbr1;
    }
    return nbr;
}

int get_mult(int ind_deb, int ind_fin)
{
    int i;
    int mult = 1;

    for (i = ind_deb; i < ind_fin; i ++) {
        mult *= 10;
    }
    return mult;
}

int my_getnbr(char const *str)
{
    int ind_deb = my_ind_deb(str);
    int ind_fin = my_ind_fin(str, ind_deb);
    long temp_nbr = 0;
    int mult;
    int sign;
    int i = ind_deb;

    if (ind_deb == my_strlen(str)) {
        return (0);
    }
    mult = get_mult(ind_deb, ind_fin);
    for (; mult >= 1; mult /= 10) {
        temp_nbr += (str[ind_deb] - 48)*mult;
        ind_deb ++;
    }
    temp_nbr *= my_getsign(str, i);
    return (long_into_int(temp_nbr));
}
