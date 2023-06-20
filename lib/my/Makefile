##
## EPITECH PROJECT, 2022
## makefile
## File description:
## wow
##
SRCMY     =     my_putchar.c                                    \
                my_strcmp.c     	                        \
                my_strncat.c    	                        \
                my_put_nbr.c    	                        \
                my_strcpy.c     	                        \
                my_strncmp.c  		                        \
                my_compute_power_rec.c	                        \
                my_putstr.c		                        \
                my_str_isalpha.c	                        \
                my_strncpy.c		                        \
                my_compute_square_root.c                        \
                my_revstr.c     	                        \
                my_str_islower.c	                        \
                my_strstr.c		                        \
                my_find_prime_sup.c	                        \
                my_showmem.c       	                        \
                my_str_isnum.c                                  \
                my_strupcase.c		                        \
                my_getnbr.c 		                        \
                my_showstr.c    	                        \
                my_str_isprintable.c	                        \
                my_swap.c		                        \
                my_sort_int_array.c	                        \
                my_str_isupper.c	                        \
                my_strdup.c                                     \
                my_isneg.c      	                        \
                my_strcapitalize.c	                        \
                my_strlen.c		                        \
                my_is_prime.c                                   \
                my_strcat.c                                     \
                my_is_in.c                                      \
                my_detect_number.c                              \
                my_strlowcase.c                                 \
                my_str_to_word_array.c                          \
                my_str_to_word_array_2.c                        \
                my_count_word.c                                 \
                my_input.c                                      \
                my_is_alpha.c                                   \
                my_strlen_charc.c                               \
                add_to_buffer.c                                 \

SRC       =     $(SRCMY)


OBJ	  =	$(SRC:.c=.o)

NAME 	  =	libmy.a

all: 	$(NAME)

$(NAME):        $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re :	fclean
	make all
