/*
** EPITECH PROJECT, 2023
** B-PSU-200-MLH-2-1-minishell1-sacha.ramstein
** File description:
** my_is_alpha
*/

int my_isalphanumeric(char str)
{
    if ((str < 97 && str > 90 ) || (str < 65 || str > 122))
        return 0;
    return 1;
}
