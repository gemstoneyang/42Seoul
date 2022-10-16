# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:52:18 by wonyang           #+#    #+#              #
#    Updated: 2022/10/16 20:51:41 by wonyang          ###   ########.fr        #
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
			  heredoc.c \

GNL			= get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c \

OBJS		= $(SRCS:%.c=%.o) $(GNL:%.c=%.o)

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
