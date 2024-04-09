##
## EPITECH PROJECT, 2024
## myteams
## File description:
## Makefile
##

ARCHIVE	=	../libs/libsocket.a \
			../libs/libarray.a \
			../libs/libdlloader.a \
			../libs/liblogging.a \
			../libs/libcompletion.a

MAIN_SRC    =	src/main.c

COMMAND_SRC	=	src/input_command/display.c \
				src/input_command/clear.c \
				src/command/help.c \
				src/command/login.c \
				src/command/quit.c \
				src/command/nothing.c

COMMON_SRC	=	../src/load_file.c \
				../src/usage.c \
				../src/args.c \
				../src/command.c \
				../src/get_env.c

FILE_SRC    =	$(COMMON_SRC) \
				$(COMMAND_SRC) \
				src/loop.c \
				src/stdin.c \
				src/server.c \
				src/disconnect.c \
				src/conn/accept.c \
				src/loop_command.c \
				src/command_parsing.c \
				src/load/load_server.c \
				src/user/create_user.c \
				src/user/delete_user.c \
				src/load/unload_server.c

TEST_SRC    =

FILE_OBJ    =    $(FILE_SRC:.c=.o)
MAIN_OBJ    =    $(MAIN_SRC:.c=.o)
TEST_OBJ    =    $(TEST_SRC:.c=_test.o)

FILE_GCDA	=	$(FILE_SRC:.c=.gcda)
FILE_GCNO	=	$(FILE_SRC:.c=.gcno)

CC    =    gcc

DEBUG	=	-g3 -DDEBUG
INCLUDE	=	-Iinclude
NO_UNUSED	=	-Wno-unused-parameter -Wno-unused-function
CFLAGS    = -Wall -Wextra -ansi -fanalyzer \
			$(NO_UNUSED) $(INCLUDE)

LIB	=	-L../libs/ -lsocket -larray -llogging -ldlloader -lcompletion
LDFLAGS    =    $(LIB)

COVERAGE    =    --coverage -lcriterion

OUTPUT_DIR	=	..
EXE    =    $(OUTPUT_DIR)/myteams_server
TEST_EXE    =    $(EXE)_test

all:    $(EXE)

%.o:    %.c
	$(CC) $(CFLAGS)   -c -o $@ $<


%_test.o:	%.o
	$(CC)   -c -o $@ $<

$(EXE):	$(FILE_OBJ) $(MAIN_OBJ) $(ARCHIVE)
	$(CC) -o $(EXE) $(FILE_OBJ) $(MAIN_OBJ) $(LDFLAGS)

debug:	CFLAGS += $(DEBUG)
debug:	$(FILE_OBJ) $(MAIN_OBJ) $(LIB_DEPENDENCY)
	$(CC) -o $(EXE) $(FILE_OBJ) $(MAIN_OBJ) $(LDFLAGS)

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
unit_tests: $(FILE_OBJ) $(TEST_OBJ) $(ARCHIVE)
	$(CC) -o $(EXE) $(FILE_OBJ) $(TEST_OBJ) $(LDFLAGS)

tests_run:    clean unit_tests
	./$(TEST_EXE) --jobs 1

.PHONY: all clean re fclean unit_tests tests_run
