SRCS	= srcs/main.c srcs/parsing_info.c srcs/dynamic.c srcs/search_bsq.c srcs/util.c

OBJS	= ${SRCS:.c=.o}

FILE_NAME = stdin_dedicated_file

HEADER	= includes

NAME	= BSQ

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

all:		${NAME}


${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} ${FILE_NAME}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all re fclean clean
