/*
** EPITECH PROJECT, 2022
** my_get_nbr
** File description:
** get nbr
*/
int my_strlen(char const *str);
long int print_legal(long int *nbr)
{
    if (*nbr > (-2147483648) && *nbr < 2147483647){
        return *nbr;
    } else {
        return 0;
    }
}

long int follow_number(char const *str)
{
    int *str_prec;
    long int nbr;
    nbr = 0;
    while (*str < 58 && *str > 47 ){
        nbr = nbr *10;
        nbr = nbr + *str - '0';
        ++str;
    }
    return print_legal(&nbr);
}

long int follow_number_negative(char const *str)
{
    int *str_prec;
    long int nbr;
    nbr = 0;
    while (*str < 58 && *str > 47 ){
        nbr = nbr *10;
        nbr = nbr + *str - '0';
        ++str;
    }
    nbr = nbr * -1;
    return print_legal(&nbr);
}

int my_getnbr(char const *str)
{
    if (str[0] == '0' && str[1] == '\0')
        return 0;
    while (str[0] != '\0') {
        if (str[0] == '-' && (str[1] >= '0' && str[1] <= '9'))
            return follow_number_negative(++str);
        if (str[0] >= '0' && str[0] <= '9')
            return follow_number(str);
        str++;
    }
    return -1;
}
