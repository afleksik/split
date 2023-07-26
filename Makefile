NAME=		split

BIN_DIR=	./bin
SRC_DIR=	./src
OBJ_DIR=	./obj
INC_DIR=	./inc

SRCS=		file_size.c get_filename.c main.c scan_part.c split_file.c
OBJS=		${SRCS:.c=.o}

CC=			gcc
CFLAGS=		-Wall -Wextra -Wpedantic -g -L${INC_DIR}
LDFLAGS=

.PHONY: clean fclean re

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

${NAME}: ${addprefix ${OBJ_DIR}/,${OBJS}}
	${CC} ${CFLAGS} -o ${BIN_DIR}/${NAME} $? ${LDFLAGS}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	rm -f ${addprefix ${OBJ_DIR}/,${OBJS}}

fclean: clean
	rm -f ${BIN_DIR}/${NAME}

re: fclean all
