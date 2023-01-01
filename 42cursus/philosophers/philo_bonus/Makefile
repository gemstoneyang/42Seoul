# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:52:18 by wonyang           #+#    #+#              #
#    Updated: 2023/01/01 19:25:02 by wonyang          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= philo_bonus
CFLAGS		= -Wall -Werror -Wextra

HEADER		= philo_bonus.h
SRCS		= main_bonus.c \
			  parse_bonus.c \
			  time_bonus.c \
			  init_bonus.c \
			  sem_bonus.c \
			  util_bonus.c \
			  ft_isinteger_bonus.c \
			  act_bonus.c \
			  print_bonus.c \
			  free_bonus.c \

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
