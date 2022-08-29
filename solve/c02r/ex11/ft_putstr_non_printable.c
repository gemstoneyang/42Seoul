/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 09:53:34 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/23 23:05:48 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printable(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

void	dec_to_hex(int decimal)
{
	int		idx;
	int		mod;
	char	hexdecimal[2];

	idx = 1;
	hexdecimal[0] = '0';
	hexdecimal[1] = '0';
	while (decimal > 0)
	{
		mod = decimal % 16;
		if (mod < 10)
			hexdecimal[idx] = '0' + mod;
		else
			hexdecimal[idx] = 'a' + (mod - 10);
		decimal /= 16;
		idx--;
	}
	ft_putchar('\\');
	write(1, hexdecimal, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_printable(str[i]) == 1)
			ft_putchar(str[i]);
		else
			dec_to_hex(str[i]);
		i++;
	}
}
