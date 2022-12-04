# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:52:18 by wonyang           #+#    #+#              #
#    Updated: 2022/12/04 17:39:32 by wonyang          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
LIBFT		= libft
LIBFT_HEADER = libft.h
LIBFT_LIB	= $(LIBFT)/libft.a
GNL			= get_next_line
GNL_HEADER	= get_next_line.h
MLX			= mlx
MLX_HEADER	= mlx.h
MLX_LIB		= libmlx.dylib
MANDATORY_DIR = mandatory
BONUS_DIR	= bonus
CFLAGS		= -Wall -Werror -Wextra

HEADERS		= $(GNL)/$(GNL_HEADER) \
			  $(MLX)/$(MLX_HEADER) \
			  $(LIBFT)/$(LIBFT_HEADER) \

M_SRCS		= main.c \
			  map.c \
			  parse.c \
			  screen.c \
			  bresenham.c \
			  rotate.c \
			  hooks.c \
			  init.c \

B_SRCS		= main_bonus.c \
			  map_bonus.c \
			  parse_bonus.c \
			  screen_bonus.c \
			  bresenham_bonus.c \
			  rotate_bonus.c \
			  hooks_bonus.c \
			  init_bonus.c \
			  control_bonus.c \

G_SRCS		= get_next_line.c \
			  get_next_line_utils.c \

MANDATORY_SRCS	= $(addprefix $(MANDATORY_DIR)/, $(M_SRCS))
BONUS_SRCS		= $(addprefix $(BONUS_DIR)/, $(B_SRCS))
GNL_SRCS		= $(addprefix $(GNL)/, $(G_SRCS))

OBJS		= $(MANDATORY_SRCS:%.c=%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)
GNL_OBJS	= $(GNL_SRCS:%.c=%.o)

ifdef WITH_BONUS
	OBJ_FILES = $(BONUS_OBJS)
	DELETE_FILES = $(OBJS)
	FDF_HEADER = $(BONUS_DIR)/fdf_bonus.h
else
	OBJ_FILES = $(OBJS)
	DELETE_FILES = $(BONUS_OBJS)
	FDF_HEADER	= $(MANDATORY_DIR)/fdf.h
endif

$(NAME) : 	$(OBJ_FILES) $(GNL_OBJS) $(LIBFT_LIB) $(MLX_LIB) $(HEADERS) $(FDF_HEADER)
			@rm -f $(DELETE_FILES)
			cc $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(GNL_OBJS) -lft -L$(LIBFT) -lmlx -L$(MLX)

all	:		$(NAME)

bonus:
			@make WITH_BONUS=1 all

$(LIBFT_LIB):
			make bonus -C $(LIBFT)/

$(MLX_LIB):	
			make -C $(MLX)/
			cp $(MLX)/$(MLX_LIB) .

%.o	: 		%.c
			cc $(CFLAGS) -c $^ -I./ -I$(MLX) -I$(LIBFT) -I$(GNL) -o $@

clean	:
			rm -f $(OBJS) $(BONUS_OBJS) $(GNL_OBJS)
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
