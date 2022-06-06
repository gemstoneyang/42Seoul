SRCS    = srcs/character_check.c srcs/field_parser.c srcs/ft_putnbr.c srcs/two_argument.c srcs/error_handler.c srcs/file_reader.c srcs/main.c srcs/one_argument.c srcs/two_argument_write.c srcs/file_reader_two.c

OBJS	=	${SRCS:.c=.o}

NAME	=	rush-02

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

HEADER	=	includes

.c.o:	${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

all:	${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re ${NAME}
