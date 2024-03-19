##
## EPITECH PROJECT, 2024
## B-NWP-400-LYN-4-1-myftp-mathieu.borel.git
## File description:
## Makefile
##

all: client server

client:
	@make -C client

server:
	@make -C server

clean:
	@make -C client clean --no-print-dir
	@make -C server clean --no-print-dir


fclean:	clean
	rm -rf coding-style-reports.log
	@make -C client fclean --no-print-dir
	@make -C server fclean --no-print-dir

re:    fclean all

unit_tests:
	@make -C client unit_tests --no-print-dir
	@make -C server unit_tests --no-print-dir

tests_run:    unit_tests

.PHONY: all clean re fclean tests_run client server
