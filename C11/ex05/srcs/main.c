/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:33:29 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/06 16:48:28 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "oper.h"

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		res;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (sign * res);
}

void	init(int (**f)(int, int))
{
	f[0] = plus;
	f[1] = minus;
	f[2] = multi;
	f[3] = div;
	f[4] = mod;
}

void	print_result(int (**f)(int, int), int oper, int a, int b)
{
	if (oper < 3)
		print_num(f[oper](a, b));
	else if (oper == 3)
	{
		if (b == 0)
		{
			write(1, "Stop : division by zero\n", 24);
			return ;
		}
		print_num(f[3](a, b));
	}
	else
	{
		if (b == 0)
		{
			write(1, "Stop : modulo by zero\n", 22);
			return ;
		}
		print_num(f[4](a, b));
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	oper;
	int	(*f[5])(int, int);

	init(f);
	if (argc != 4)
		return (0);
	if (is_oper(argv[2]) == -1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	oper = is_oper(argv[2]);
	print_result(f, oper, ft_atoi(argv[1]), ft_atoi(argv[3]));
	return (0);
}
