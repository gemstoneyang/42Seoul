# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:52:18 by wonyang           #+#    #+#              #
#    Updated: 2022/10/02 16:09:35 by wonyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
LIBFT		= libft

SRCS		= test.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Werror -Wextra -g3 -fsanitize=address

$(NAME) : 	$(OBJS)
			make bonus -C $(LIBFT)/
			cc $(FLAGS) -o $(NAME) $(OBJS) -lft -L$(LIBFT)

all	:		$(NAME) $(CH_NAME)

%.o	: 		%.c
			cc $(FLAGS) -c $^ -I./ -o $@

clean	:
			rm -f $(OBJS) $(CH_OBJS)
			make clean -C $(LIBFT)

fclean	:	
			make clean
			rm -f $(NAME) $(CH_NAME)
			make fclean -C $(LIBFT)

re	:		
			make fclean
			make all

.PHONY	:	all clean fclean re
