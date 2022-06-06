/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:43:06 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/24 18:45:42 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nbr(int n)
{
	int		i;
	char	num[10];

	i = 0;
	while (n > 0)
	{
		num[i] = '0' + n % 10;
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &num[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
	{
		write(1, "-", 1);
		print_nbr(-nb);
	}
	else
		print_nbr(nb);
}
