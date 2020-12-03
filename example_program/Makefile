CC = gcc
CFLAGS = -W -Wall -I../include -L../
LFLAGS = -lmarble
TARGET = example_program

SRC = 	main.c \

TESTS =	\

all: build_lib build_all

build_lib:
	make -C ../

build_all: ${TARGET}

$(TARGET): ${SRC}
	${CC} ${CFLAGS} -o ${TARGET} ${SRC} ${LFLAGS}

clean:
	rm -f ${TARGET}

fclean: clean
	rm -f ${LIB} *.gc*

re: fclean all
