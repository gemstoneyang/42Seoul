/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:46:06 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 21:12:43 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_number(char c);

int	ft_atoi(char *str)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_number(*str))
	{
		number *= 10;
		number += (*str - '0');
		str++;
	}
	return (sign * number);
}

int	check_exception(int fd, int nb)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	if (nb == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}

void	putnbr(int fd, int nb)
{
	char	c;

	if (nb > 0)
	{
		putnbr(fd, nb / 10);
		c = nb % 10 + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr(int fd, int nb)
{
	if (!check_exception(fd, nb))
	{	
		if (nb < 0)
		{	
			nb *= -1;
			write(fd, "-", 1);
		}
		putnbr(fd, nb);
	}	
}
