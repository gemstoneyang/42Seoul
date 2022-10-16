# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:52:18 by wonyang           #+#    #+#              #
#    Updated: 2022/10/16 17:18:43 by wonyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
LIBFT		= libft

SRCS		= main.c \
			  parse_path.c \
			  utils.c \
			  exit.c \
			  execve.c \
			  fork.c \

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Werror -Wextra

$(NAME) : 	$(OBJS)
			make bonus -C $(LIBFT)/
			cc $(FLAGS) -o $(NAME) $(OBJS) -lft -L$(LIBFT)

all	:		$(NAME) $(CH_NAME)

%.o	: 		%.c
			cc $(FLAGS) -c $^ -I./ -o $@

clean	:
			rm -f $(OBJS)
			make clean -C $(LIBFT)

fclean	:	
			make clean
			rm -f $(NAME)
			make fclean -C $(LIBFT)

re	:		
			make fclean
			make all

.PHONY	:	all clean fclean re
