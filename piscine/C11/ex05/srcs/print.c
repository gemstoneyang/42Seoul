/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:51:43 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/06 15:22:07 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n / 10 == 0)
	{
		write(1, &"0123456789"[n % 10], 1);
		return ;
	}
	print_num(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	return ;
}

int	is_oper(char *op)
{
	int		i;
	char	c;

	i = 0;
	while (op[i])
		i++;
	if (i != 1)
		return (-1);
	c = op[0];
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
		return (3);
	else if (c == '%')
		return (4);
	return (-1);
}
