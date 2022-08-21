# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 01:02:51 by wonyang           #+#    #+#              #
#    Updated: 2022/08/21 20:03:55 by wonyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft

SRCS		= mandatory/main.c \
			  mandatory/stack.c \
			  mandatory/init_data.c \
			  mandatory/error.c \
			  mandatory/parse.c \
			  mandatory/cmd_swap.c \
			  mandatory/cmd_push.c \
			  mandatory/cmd_rotate.c \
			  mandatory/cmd_rev_rotate.c \
			  mandatory/validation.c \
			  mandatory/sort.c \
			  mandatory/utils.c \
			  mandatory/cmd_div.c \
			  mandatory/pivot.c \
			  mandatory/three_div_a_to_b.c \
			  mandatory/three_div_b_to_a.c \
			  mandatory/cmd_list.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

all	:		$(NAME)

$(NAME) : 	$(OBJS)
			make bonus -C $(LIBFT)/
			cc -o $(NAME) $(OBJS) -lft -L$(LIBFT)

%.o	: 		%.c
			cc $(FLAGS) -c $^ -I./ -o $@

clean	:
			rm -f $(OBJS)
			make clean -C $(LIBFT)

fclean	:	clean
			rm -f $(NAME)
			make fclean -C $(LIBFT)

re	:		fclean all

.PHONY	:	all clean fclean re
