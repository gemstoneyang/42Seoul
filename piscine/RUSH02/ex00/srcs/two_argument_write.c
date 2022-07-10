/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_argument_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:36:56 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 21:07:26 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two_argument_write.h"

void	write_space(int fd, int space_num)
{
	int	i;

	i = -1;
	while (++i < space_num)
		write(fd, " ", 1);
}

void	write_digit_num(int fd, int digit_num)
{
	write(fd, "1", 1);
	while (--digit_num > 0)
		write(fd, "0", 1);
}

void	write_dict(int fd, t_dict *dict)
{
	char	*str;

	ft_putnbr(fd, dict->key);
	write_space(fd, dict->l_space);
	write(fd, ":", 1);
	write_space(fd, dict->r_space);
	str = dict->value;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
	write(fd, "\n", 1);
}

void	write_digit_dict(int fd, t_digit_dict *digit_dict)
{
	char	*str;

	write_digit_num(fd, digit_dict->digit);
	write_space(fd, digit_dict->l_space);
	write(fd, ":", 1);
	write_space(fd, digit_dict->r_space);
	str = digit_dict->value;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
	write(fd, "\n", 1);
}
