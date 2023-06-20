/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** compare n char
*/
int compare_ascii_n(char const *s1, char const *s2)
{
    if (s1[0] < s2[0])
        return s2[0]-s1[0];
    else
        return s1[0]-s2[0];
}

int my_strncmp (char const *s1, char const *s2,int n)
{
    int i = 0;
    while ((s1[0] != '\0' || s2[0] != '\0') && n > i) {
        if (s1[0] != s2[0])
            return compare_ascii_n(s1,s2);
        s1++;
        s2++;
        i++;
    }
    return 0;
}
