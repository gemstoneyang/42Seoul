
SRCS	= srcs/main.c srcs/oper.c srcs/print.c

OBJS	= ${SRCS:.c=.o}

NAME	= do-op

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

HEADER	= includes

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re ${NAME}
