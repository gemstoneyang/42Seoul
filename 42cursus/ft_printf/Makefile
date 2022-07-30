# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 18:32:17 by wonyang           #+#    #+#              #
#    Updated: 2022/07/31 03:03:38 by wonyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS					= ft_printf.c \
					  ft_printf_utils.c \
					  ft_printf_update_info.c \
					  ft_printf_persent.c \
					  ft_printf_di.c \
					  ft_printf_di_utils.c
					  

BNS_SRCS				=

OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS					= -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(BNS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all	:	$(NAME)

$(NAME) : $(OBJ_FILES)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJ_FILES)

%.o			: %.c
	gcc $(FLAGS) -c $^ -I./ -o $@

bonus :
	make WITH_BONUS=1 all

clean	:
		rm -f $(OBJS) $(BNS_OBJS)
		make clean -C $(LIBFT)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re	:	fclean all

.PHONY	:	all clean fclean re bonus
