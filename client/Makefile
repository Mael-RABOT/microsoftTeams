##
## EPITECH PROJECT, 2024
## myteams
## File description:
## Makefile
##

MAIN_SRC    =	src/main.c

FILE_SRC    =

TEST_SRC    =

FILE_OBJ    =    $(FILE_SRC:.c=.o)
MAIN_OBJ    =    $(MAIN_SRC:.c=.o)
TEST_OBJ    =    $(TEST_SRC:.c=_test.o)

FILE_GCDA	=	$(FILE_SRC:.c=.gcda)
FILE_GCNO	=	$(FILE_SRC:.c=.gcno)

CC    =    gcc

DEBUG	=	-g3
INCLUDE	=	-Iinclude -I../include
NO_UNUSED	=	-Wno-unused-parameter -Wno-unused-function
CFLAGS    = -Wall -Wextra -ansi -pedantic -fanalyzer \
			$(NO_UNUSED) $(INCLUDE)

LIB	=
LDFLAGS    =    $(LIB)

COVERAGE    =    --coverage -lcriterion

OUTPUT_DIR	=	..
EXE    =    $(OUTPUT_DIR)/myteams_cli
TEST_EXE    =    $(EXE)_test

all:    $(EXE)

%.o:	%.c
	$(CC) $(CFLAGS)   -c -o $@ $<

%_test.o:	%.o
	$(CC)   -c -o $@ $<

$(EXE):	$(FILE_OBJ) $(MAIN_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

debug:	CFLAGS += $(DEBUG)
debug:	LDFLAGS += -DDEBUG
debug:	$(FILE_OBJ) $(MAIN_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(MAIN_OBJ) $(TEST_OBJ) $(FILE_OBJ)
	rm -rf $(FILE_GCNO) $(FILE_GCDA)
	rm -rf coding-style-reports.log
	$(shell find * -name "vgcore.*" -delete)

fclean:	clean
	rm -rf $(EXE)
	rm -rf $(TEST_EXE)

re:    fclean all

unit_tests:	CFLAGS += $(COVERAGE) -DTEST
unit_tests: LDFLAGS += $(COVERAGE)
unit_tests: $(FILE_OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST_EXE) $^ $(LDFLAGS)

tests_run:    clean unit_tests
	./$(TEST_EXE) --jobs 1

.PHONY: all clean re fclean unit_tests tests_run
