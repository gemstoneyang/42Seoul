# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 01:02:51 by wonyang           #+#    #+#              #
#    Updated: 2022/09/12 15:38:02 by wonyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CH_NAME		= checker
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

CH_SRCS		= bonus/get_next_line/get_next_line.c \
			  bonus/get_next_line/get_next_line_utils.c \
			  bonus/check_result.c \
			  bonus/cmd_div.c \
			  bonus/cmd_push.c \
			  bonus/cmd_rev_rotate.c \
			  bonus/cmd_rotate.c \
			  bonus/cmd_swap.c \
			  bonus/error.c \
			  bonus/init_data.c \
			  bonus/main.c \
			  bonus/parse.c \
			  bonus/stack.c \
			  bonus/utils.c \
			  bonus/validation.c

OBJS		= $(SRCS:%.c=%.o)
CH_OBJS		= $(CH_SRCS:%.c=%.o)

FLAGS		= -Wall -Werror -Wextra -fsanitize=address -g3

$(NAME) : 	$(OBJS)
			make bonus -C $(LIBFT)/
			cc $(FLAGS) -o $(NAME) $(OBJS) -lft -L$(LIBFT)

all	:		$(NAME) $(CH_NAME)

bonus :		$(CH_NAME)

$(CH_NAME):	$(CH_OBJS)
			make bonus -C $(LIBFT)/
			cc $(FLAGS) -o $(CH_NAME) $(CH_OBJS) -lft -L$(LIBFT)

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

.PHONY	:	all clean fclean re bonus
