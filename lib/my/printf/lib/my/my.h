/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** task02 day09
*/

#ifndef MY_
    #define MY_
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr_base(char const *, char const *);
int my_getnbr(char const *);
int my_getsign(char const *, int);
char *convert_base(char const *, char const *, char const *);
int my_isneg(int);
int my_is_prime(int);
void my_putchar(char);
char *my_putnbr_base(int, char const *);
int my_put_nbr(int);
int my_putstr(char const *);
char *my_revstr(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
void my_sort_int_array(int *, int);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
void my_swap(int *, int *);
int my_show_word_array(char *const *);
int my_ideb(char const *, char const *);
int my_ifin(char const *, int, char const *);
int long_to_int(long);
int recup_val(char, char const *);
int recup_div(int, int);
int find_div(int);
void cas_xtrm(int);
int count_words(char *const *);
void comp(int, int *);
char lowchar(char);
int verif_word(char *, char const *);
int test_an(char);
int nb_mot(char const *);
int nb_char_next(char const *, int);
char *create_str(char const *, int);
int my_ind_deb(char const *);
int my_ind_fin(char const *, int);
int long_into_int(long);
int get_mult(int, int);
char *my_strdup(char const *);
#endif /* MY_ */
