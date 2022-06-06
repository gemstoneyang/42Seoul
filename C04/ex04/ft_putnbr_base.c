/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:46:48 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/25 18:29:29 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_length(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	check_same_char(char c, char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == c)
			return (1);
		i++;
	}
	arr[i] = c;
	return (0);
}

int	is_exception(char *base)
{
	int		i;
	char	arr[300];

	i = 0;
	while (i < 300)
	{
		arr[i] = '\0';
		i++;
	}
	if (base_length(base) <= 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (check_same_char(base[i], arr) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	print_base(long n, char *base, long len)
{
	if (n / len == 0)
	{
		write(1, &base[n % len], 1);
		return ;
	}
	print_base(n / len, base, len);
	write(1, &base[n % len], 1);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;

	if (is_exception(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -(long)nbr;
	}
	else
		n = (long)nbr;
	print_base(n, base, base_length(base));
}
