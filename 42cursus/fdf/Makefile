# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:52:18 by wonyang           #+#    #+#              #
#    Updated: 2022/12/02 18:37:45 by wonyang          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
FDF_HEADER	= fdf.h
LIBFT		= libft
LIBFT_HEADER = libft.h
LIBFT_LIB	= $(LIBFT)/libft.a
GNL			= get_next_line
GNL_HEADER	= get_next_line.h
MLX			= mlx
MLX_HEADER	= mlx.h
MLX_LIB		= libmlx.dylib
SRC_DIR		= srcs

HEADERS		= $(GNL)/$(GNL_HEADER) \
			  $(MLX)/$(MLX_HEADER) \
			  $(LIBFT)/$(LIBFT_HEADER) \

SRCS		= main.c \
			  exit.c \
			  map.c \
			  parse.c \
			  ftcntl.c \
			  utils.c \
			  screen.c \
			  bresenham.c \
			  filter.c \
			  rotate.c \
			  hooks.c \
			  mlx.c \

GNL_SRCS	= get_next_line.c \
			  get_next_line_utils.c \

MANDATORY_SRCS = $(addprefix $(SRC_DIR)/, $(SRCS)) $(addprefix $(GNL)/, $(GNL_SRCS))

OBJS		= $(MANDATORY_SRCS:%.c=%.o)

CFLAGS		= -Wall -Werror -Wextra

$(NAME) : 	$(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(HEADERS) $(SRC_DIR)/$(FDF_HEADER)
			cc $(CFLAGS) -o $(NAME) $(OBJS) -lft -L$(LIBFT) -lmlx -L$(MLX)

all	:		$(NAME)

bonus:		all

$(LIBFT_LIB):
			make bonus -C $(LIBFT)/

$(MLX_LIB):	
			make -C $(MLX)/
			cp $(MLX)/$(MLX_LIB) .

%.o	: 		%.c
			cc $(CFLAGS) -c $^ -I./ -I$(MLX) -I$(LIBFT) -I$(GNL) -o $@

clean	:
			rm -f $(OBJS)
			make clean -C $(LIBFT)

fclean	:	
			make clean
			make clean -C $(MLX)
			rm -f $(NAME)
			rm -f $(MLX_LIB)
			make fclean -C $(LIBFT)

re	:		
			make fclean
			make all

.PHONY	:	all clean fclean re bonus
