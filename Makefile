SRC_DIR = src
INCLUDE_DIR = include
SRC = ${wildcard $(SRC_DIR)/*.c}
NAME    = bsq
OBJS    = *.c
CC      = gcc -Wall -Wextra -Werror
RM      = rm -f
CFLAGS  = -Wall -Werror -Wextra
.c.o:
			$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
${NAME}:    ${OBJS}
			${CC} -o ${NAME} ${OBJS}
all:		${NAME}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		all clean fclean re
