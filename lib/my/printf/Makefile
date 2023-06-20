##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile pour myprintf
##

FICC	=	my_printf.c \
		my_dispfunc.c \
		lib/my/my_compute_power_rec.c \
		lib/my/my_putchar.c \
		lib/my/my_putnbr_base.c \
		lib/my/my_put_nbr.c \
		lib/my/my_putstr.c \
		lib/my/my_strdup.c \
		lib/my/my_strlen.c \
		lib/my/my_strncpy.c \
		lib/my/my_putfloat_base.c \
		lib/my/nb_diz.c \
		lib/my/getstr_non_char.c \
		lib/my/my_putnstr.c \
		lib/my/my_putnbr_base.c \
		lib/my/my_revstr.c \
		lib/my/my_getnbr.c \
		lib/my/my_putfloat_base.c \
		lib/my/my_strcat.c \
		lib/my/my_get_sign.c \
		lib/my/my_getnbr.c \
		lib/my/my_str_round.c \
		lib/my/my_showstr.c \
		my_dispfunc2.c \
		my_dispfunc3.c \
		my_dispfunc4.c \
		my_dispfunc5.c \
		my_dispfunc6.c \
		my_dispfunc7.c \
		my_getfunc1.c \
		my_getfunc2.c \
		my_getfunc3.c \
		my_getfunc4.c \
		my_format_func1.c \
		my_strlen_free.c \
		my_format_func2.c \
		shortcut.c \
		my_format_func3.c \
		my_dispfunc_test1.c \
		my_dispfunc_test2.c \
		my_dispfunc_test3.c

FICO	=	$(FICC:.c=.o)

LIB_NAME	=	libpf.a

NAME_EXE	=	a.out

FICTEST	=	tests/test_specifier2.c

all:	$(LIB_NAME)

clean:
	rm -f $(FICO)
	rm -f *~
	rm -f coding-style-reports*
	rm -f vgcore*

fclean:	clean
	rm -f ./myprintf
	rm -f $(LIB_NAME)
	rm -f $(NAME_EXE)

re:	fclean / all

$(LIB_NAME):$(FICO)
	ar rc $(LIB_NAME) $(FICO)

cstyle:	fclean
	coding-style . .
	cat coding-style-reports.log

compil:
	gcc -g -o $(NAME_EXE) main.c -Iinclude -L. -lmy
