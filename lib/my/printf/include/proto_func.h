/*
** EPITECH PROJECT, 2022
** proto_func.h
** File description:
** proto pour printf
*/

#include <stdarg.h>

#ifndef PROTO_FUNC_
    #define PROTO_FUNC_
int disp_percent(va_list, char *, int);
int dispnb(va_list, char *, int);
int get_diz(long);
int dispstr(va_list, char *, int);
int dispchar(va_list, char *, int);
int disp_majs(va_list, char *, int);
int disp_binary(va_list, char *, int);
int disp_octal(va_list, char *, int);
int disp_hexa(va_list, char *, int);
int disp_hexa_maj(va_list, char *, int);
int disp_unsigned(va_list, char *, int);
int disp_flagf(va_list, char *, int);
int disp_flagf_maj(va_list, char *, int);
int disp_scien(va_list, char *, int);
int disp_scien_maj(va_list, char *, int);
int my_putfloat(double, double, int);
int disp_flagp(va_list, char *, int);
double round_double(double, double);
int disp_sc_hex(va_list, char *, int);
int disp_scienf(double, double, int);
int disp_scien_majf(double, double, int);
int get_exp(double);
int disp_flagg(va_list, char *, int);
int disp_flagg_maj(va_list, char *, int);
int putstr_non_char(char *, char);
int get_binary(va_list, char *, int);
int get_hexa(va_list, char *, int);
int get_unsigned(va_list, char *, int);
int getnb(va_list, char *, int);
int get_char(va_list, char *, int);
int getstr(va_list, char *, int);
int get_majs(va_list, char *, int);
int get_octal(va_list, char *, int);
int my_getfloat(double, double, int);
int get_flagf(va_list, char *, int);
int getstr_non_char(char *, char);
int get_scien(va_list, char *, int);
int get_scienf(double, double, int);
int get_pourcent(va_list, char *, int);
int get_flagg(va_list, char *, int);
int get_flagp(va_list, char *, int);
int my_put_param(char, va_list, char *, int);
int my_putformat(const char *, int, va_list, va_list);
int my_get_param(char, va_list, char *, int);
int get_len(char const *, int);
int my_strlen_free(char const *);
int disp_sc_hex_maj(va_list, char *, int);
char *disp_sc_hexpos_maj(double, char, int, char *);
int get_sc_hex(va_list, char *, int);
int my_putspace(char *, va_list, va_list);
char recup_flag(char *);
int recup_width(char *, va_list, va_list);
int precision (char *, va_list, va_list);
int in_tab(char *, char);
char signeplus (char const *format);
char *recup_format(char const *str, int index);
int recup_prs(char *, va_list, va_list);
int size_tab(char*);
int char_isprint(char);
int my_printf(const char *restrict, ...);
int dispnb_test(int, int);
int dispstr_test(char *, int);
int dispchar_test(char);
int disp_majs_test(char *, int);
int disp_binary_test(unsigned int, char *, int);
int disp_hexa_test(unsigned int, char *, int);
int disp_hexa_maj_test(unsigned int, char *, int);
int disp_unsigned_test(unsigned int, int);
int disp_octal_test(unsigned int, char *, int);
int disp_flagf_test(double, int);
int disp_flagf_maj_test(double, int);
int disp_flagg_test(double, int);
int disp_flagg_maj_test(double, int);
int disp_flagp_test(char *, int);
int disp_inf_or_nan(double, int);
int get_inf_or_nan(double);
int flagg_neg(double, char *);
int get_flagg_neg(double);
#endif /* PROTO_FUNC_ */
