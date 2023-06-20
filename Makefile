##
## EPITECH PROJECT, 2023
## corewar
## File description:
## corewar
##

all	:
	make -C ./lib/my
	make -C ./lib/my/printf
	make -C ./asm/
	make -C ./corewar/

clean :
	make -C ./asm clean
	make -C ./corewar clean
	make -C ./lib/my clean
	make -C ./lib/my/printf clean

fclean: clean
	make -C ./corewar fclean
	make -C ./asm fclean
	make -C ./lib/my fclean
	make -C ./lib/my/printf fclean

re: fclean	all
	make -C ./lib/my re
	make -C ./lib/my/printf re
