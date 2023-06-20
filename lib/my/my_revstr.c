/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverse
*/
char my_strlen(char const *str);
char *my_revstr ( char *str )
{
    int i;
    int neg_i = my_strlen(str)-1;
    char temp[my_strlen(str)-1];
    for (i = 0;str[i] != '\0';i++){
        temp[i] = str[i];
    }
    for (i = 0;str[i] != '\0';i++){
        str[i] = temp[neg_i];
        neg_i--;
    }
    return str;
}
