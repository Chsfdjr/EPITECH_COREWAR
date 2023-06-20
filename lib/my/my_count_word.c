/*
** EPITECH PROJECT, 2023
** B-PSU-200-MLH-2-1-bsminishell1-sacha.ramstein
** File description:
** my_count_word
*/

int count_word(char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if ((str[i] != ' ' && str[i] != '\t' && i == 0)
            || (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t')
            && str[i] != ' ' && str[i] != '\t'))
            count++;
    }
    return count;
}

int count_separator(char *str, char separator)
{
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == separator)
            count++;
    }
    return count;
}

int count_line(char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n')
            count++;
    }
    return count;
}
