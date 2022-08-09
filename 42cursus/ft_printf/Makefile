# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 18:32:17 by wonyang           #+#    #+#              #
#    Updated: 2022/08/09 13:15:22 by wonyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ft_printf.c \
			ft_printf_utils.c \
			ft_printf_update_info.c \
			ft_printf_persent.c \
			ft_printf_di.c \
			ft_printf_di_utils.c \
			ft_printf_u.c \
			ft_printf_u_utils.c \
			ft_printf_c.c \
			ft_printf_s.c \
			ft_printf_xX.c \
			ft_printf_xX_utils.c \
			ft_printf_p.c \
			ft_printf_p_utils.c

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all	:		$(NAME)

$(NAME)	: 	$(OBJS)
			make all -C $(LIBFT)/
			cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
			$(LIBC) $(NAME) $(OBJS)

%.o	: 		%.c
			gcc $(FLAGS) -c $^ -I./ -o $@

bonus	: 	$(NAME)

clean	:
			rm -f $(OBJS)
			make clean -C $(LIBFT)

fclean	:	clean
			rm -f $(NAME)
			rm -f $(LIBFT_LIB)
			make fclean -C $(LIBFT)

re	:		fclean all

.PHONY	:	all clean fclean re bonus
