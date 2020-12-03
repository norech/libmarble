##
## MARBLE
## 
## Project by:
## Alexis "Norech" CHERON
##

CC = gcc

AR = ar rc

CFLAGS = -W -Wall -Werror -pedantic -I./include

CFLAGS_TEST = ${CFLAGS} --coverage

LFLAGS = 

LFLAGS_TEST = ${LFLAGS} -lcriterion

TESTDIR = tests

SRC =	src/json/lexer/mrbl_array_close.c \
	src/json/lexer/mrbl_array_open.c \
	src/json/lexer/mrbl_object_close.c \
	src/json/lexer/mrbl_object_open.c \
	src/json/lexer/mrbl_comma.c \
	src/json/lexer/mrbl_float.c \
	src/json/lexer/mrbl_bool.c \
	src/json/lexer/mrbl_integer.c \
	src/json/lexer/mrbl_null.c \
	src/json/lexer/mrbl_pair_separator.c \
	src/json/lexer/mrbl_string.c \
	src/json/lexer/mrbl_whitespace.c \
	src/json/parser/mrbl_parse_json_array.c \
	src/json/parser/mrbl_parse_json_object.c \
	src/json/parser/mrbl_parse_json_value.c \
	src/json/parser.c \
	src/util/lexer_helpers.c \
	src/util/mrbl_addchar.c \
	src/util/mrbl_expand_string.c \
	src/util/mrbl_strcpy.c \
	src/util/mrbl_strlen.c \
	src/util/mrbl_strdup.c \
	src/util/mrbl_free.c

TEST_FILES = 	${TESTDIR}/test_parser.c \
		${TESTDIR}/test_mrbl_string.c \
		${TESTDIR}/test_mrbl_null.c \
		${TESTDIR}/test_mrbl_float.c  \
		${TESTDIR}/test_mrbl_integer.c  \
		${TESTDIR}/test_mrbl_bool.c \
		${TESTDIR}/test_mrbl_parse_json_value.c \
		${TESTDIR}/test_mrbl_free_object.c \
		${TESTDIR}/test_mrbl_free_array.c

OBJ = ${SRC:.c=.o}

TARGET = libmarble.a

TARGET_TEST = unit_tests

all: build_all clean

build_all: ${OBJ}
	${AR} ${TARGET} ${OBJ}

tests_run: clean_tests
	${CC} ${CFLAGS} ${CFLAGS_TEST} -o ${TARGET_TEST} ${SRC} ${TEST_FILES} ${LFLAGS} ${LFLAGS_TEST}
	./${TARGET_TEST} --verbose

clean_tests:
	rm -rf ${TARGET_TEST}

coverage: test
	gcovr

clean:
	rm -f ${OBJ} *.gc* unit_test

fclean: clean
	rm -f ${TARGET}

re: fclean all
