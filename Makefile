NAME=        split

BIN_DIR=    ./bin
SRC_DIR=    ./src
OBJ_DIR=    ./obj
INC_DIR=    ./inc

SRCS=        file_size.c get_filename.c scan_part.c split_file.c main.c
OBJS=        ${SRCS:.c=.o}

CC=            gcc
CFLAGS=        -Wall -Wextra -Wpedantic -g -I${INC_DIR}
LDFLAGS=

.PHONY: all clean fclean re

all: ${BIN_DIR}/${NAME}

${BIN_DIR}/${NAME}: ${addprefix ${OBJ_DIR}/,${OBJS}}
	@mkdir -p ${BIN_DIR}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@mkdir -p ${OBJ_DIR}
	${CC} ${CFLAGS} -c -o $@ $<

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ${BIN_DIR}

re: fclean all