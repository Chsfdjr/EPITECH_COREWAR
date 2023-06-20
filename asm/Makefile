##
## EPITECH PROJECT, 2023
## corewar
## File description:
## recreating a fight
##

SRC		=	main.c\
			asm_read_file.c\
			asm_write_file.c\
			asm_handling_functions.c\
			asm_handling_functions_before_write.c\
			binary_to_dec.c\
			free_functions.c\
			asm_binary_fct.c\
			asm_handle_fct2.c\
			handle_instruction_files/instruction_add.c\
			handle_instruction_files/instruction_aff.c\
			handle_instruction_files/instruction_and.c\
			handle_instruction_files/instruction_fork.c\
			handle_instruction_files/instruction_ld.c\
			handle_instruction_files/instruction_ldi.c\
			handle_instruction_files/instruction_lfork.c\
			handle_instruction_files/instruction_live.c\
			handle_instruction_files/instruction_lld.c\
			handle_instruction_files/instruction_lldi.c\
			handle_instruction_files/instruction_or.c\
			handle_instruction_files/instruction_st.c\
			handle_instruction_files/instruction_sti.c\
			handle_instruction_files/instruction_sub.c\
			handle_instruction_files/instruction_xor.c\
			handle_instruction_files/instruction_zjmp.c\
			memset_home.c\

OBJ		=	$(SRC:.c=.o)

NAME	=	asm

CFLAGS	+=	-Wall -I../include -lmy -L../lib/my -lpf -L../lib/my/printf -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAG) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
