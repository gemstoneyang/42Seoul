# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:52:18 by wonyang           #+#    #+#              #
#    Updated: 2022/12/30 20:36:19 by wonyang          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CFLAGS		= -Wall -Werror -Wextra

HEADER		= philo.h
SRCS		= main.c \
			  ft_isinteger.c \
			  parse.c \
			  time.c \
			  init.c \
			  print.c \
			  free.c \
			  act.c \
			  monitor.c \
			  mutex.c \

OBJS		= $(SRCS:%.c=%.o)

all	:		$(NAME)

$(NAME) : 	$(OBJS) $(HEADER)
			cc $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

%.o	: 		%.c
			cc $(CFLAGS) -c $^ -I./ -o $@

clean	:
			rm -f $(OBJS)

fclean	:	
			make clean
			rm -f $(NAME)

re	:		
			make fclean
			make all

.PHONY	:	all clean fclean re
