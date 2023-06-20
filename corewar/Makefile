##
## EPITECH PROJECT, 2023
## corewar
## File description:
## recreating a fight
##

SRC			=	main.c\
				corewar.c\
\
				struct/init_cycle.c\
				struct/init_struct.c\
				struct/init_struct_champion.c\
				struct/init_arena.c\
				struct/free_struct.c\
\
				flag/corewar_dump.c\
				flag/corewar_h.c\
				flag/corewar_n.c\
				flag/corewar_a.c\
				flag/corewar_flag.c\
				flag/corewar_champion.c\
\
				tools/my_strncmp_inv.c\
				tools/my_count_champ.c\
				tools/print_mem.c\
				tools/int_to_binary.c\
				tools/big_endian_to_little_endian.c\
				tools/is_a_champ.c\
				tools/my_strndup.c\
				tools/coding_byte.c\
				tools/get_params.c\
				tools/my_intdup.c\
\
				instruction/add_instruction.c\
				instruction/aff_instruction.c\
				instruction/and_instruction.c\
				instruction/fork_instruction.c\
				instruction/lfork_instruction.c\
				instruction/live_instruction.c\
				instruction/lload_i_instruction.c\
				instruction/lload_instruction.c\
				instruction/load_i_instruction.c\
				instruction/load_instruction.c\
				instruction/or_instruction.c\
				instruction/store_i_instruction.c\
				instruction/store_instruction.c\
				instruction/substract_instruction.c\
				instruction/xor_instruction.c\
				instruction/zjmp_instruction.c\

OBJ		=	$(SRC:.c=.o)

NAME	=	corewar

CFLAGS	+=	-Wall -I../include -lmy -L../lib/my -lpf -L../lib/my/printf -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAG) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
