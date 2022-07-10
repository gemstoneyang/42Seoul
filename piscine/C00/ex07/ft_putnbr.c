/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:56:27 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/19 16:25:03 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	int_to_char(int n)
{
	char	c[12];
	int		idx;

	idx = 0;
	while (n > 0)
	{
		c[idx] = n % 10 + 48;
		idx++;
		n /= 10;
	}
	idx--;
	while (idx >= 0)
	{
		write(1, &c[idx], 1);
		idx--;
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
		nb = nb * -1;
		write(1, "-", 1);
		int_to_char(nb);
	}
	else
		int_to_char(nb);
}
