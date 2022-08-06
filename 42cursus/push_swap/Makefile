# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 01:02:51 by wonyang           #+#    #+#              #
#    Updated: 2022/08/05 02:24:01 by wonyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= main.c \
			  stack.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

all	:	$(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	gcc -o $(NAME) $(OBJS) -lft -Llibft

%.o			: %.c
	gcc $(FLAGS) -c $^ -I./ -o $@

clean	:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean	:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re	:	fclean all

.PHONY	:	all clean fclean re
