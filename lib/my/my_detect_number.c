/*
** EPITECH PROJECT, 2023
** B-CPE-110-MLH-1-1-antman-sacha.ramstein
** File description:
** my_detect_number
*/

int detect_number(int i, const char *format)
{
    int nbr = 0;
    int nbr_value = 0;
    while (format[i] > 47 && format[i] < 58) {
        nbr_value++;
        nbr = nbr * 10;
        nbr = nbr + format[i] - '0';
        i++;
    }
    if (nbr_value == 0)
        return -1;
    return nbr;
}
