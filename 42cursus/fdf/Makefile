# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:52:18 by wonyang           #+#    #+#              #
#    Updated: 2022/11/16 13:54:40 by wonyang          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
LIBFT		= libft
GNL			= get_next_line
MLX			= mlx
MLX_LIB		= libmlx.dylib

SRCS		= main.c \
			  exit.c \
			  map.c \
			  parse.c \
			  ftcntl.c \
			  utils.c \

GNL_SRCS	= $(GNL)/get_next_line.c \
			  $(GNL)/get_next_line_utils.c \

OBJS		= $(SRCS:%.c=%.o) $(GNL_SRCS:%.c=%.o)

FLAGS		= -Wall -Werror -Wextra

$(NAME) : 	$(OBJS) $(MLX_LIB)
			make bonus -C $(LIBFT)/
			cc $(FLAGS) -o $(NAME) $(OBJS) -lft -L$(LIBFT) -lmlx -L$(MLX)

all	:		$(NAME)

bonus:		all

$(MLX_LIB):	
			make -C $(MLX)/
			cp $(MLX)/$(MLX_LIB) .

%.o	: 		%.c
			cc $(FLAGS) -c $^ -I./ -I$(MLX) -I$(LIBFT) -I$(GNL) -o $@

clean	:
			rm -f $(OBJS)
			make clean -C $(LIBFT)
			make clean -C $(MLX)

fclean	:	
			make clean
			rm -f $(NAME)
			rm -f $(MLX_LIB)
			make fclean -C $(LIBFT)

re	:		
			make fclean
			make all

.PHONY	:	all clean fclean re bonus
