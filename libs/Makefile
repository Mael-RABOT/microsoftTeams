##
## EPITECH PROJECT, 2024
## B-NWP-400-LYN-4-1-myftp-mathieu.borel.git
## File description:
## Makefile
##

LIB	=	socket \
		array \
		dlloader \
		logging

all:
	@$(foreach X, $(LIB), make -C $X --print-dir;)

clean:
	@$(foreach X, $(LIB), make -C $X clean --print-dir;)

fclean:	clean
	@$(foreach X, $(LIB), make -C $X fclean --print-dir;)

re:    fclean all

.PHONY: all clean fclean re
