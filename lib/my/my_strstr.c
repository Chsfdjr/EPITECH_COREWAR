/*
** EPITECH PROJECT, 2022
** My_strstr
** File description:
** idk the principe
*/

#include <stdio.h>

char my_strlen(char const *str);

char my_str_continue(char *str, char const *to_find,int i)
{
    int j;
    for ( j = 0;j < my_strlen(to_find) ; j++ ) {
        if (str[i] != to_find[j]) {
            return 1;
        } else {
            i++;
        }
    }
    return 0;
}

char *my_strstr(char *str , char const *to_find )
{
    if (my_strlen(to_find) == 0)
        return str;
    int i = 0;
    while (str[0] != '\0'){
        if (str[0] == to_find[0] && my_str_continue(str, to_find,i) == 0){
                return str;
        }
        str++;
    }
    return NULL;
}
