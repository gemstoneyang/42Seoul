/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:25:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/24 09:41:02 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	decimal_to_hex(unsigned long long decimal, int len)
{
	int		idx;
	int		mod;
	char	hexdecimal[16];

	idx = 0;
	while (idx < len)
	{
		hexdecimal[idx] = '0';
		idx++;
	}
	idx--;
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
	write(1, hexdecimal, len);
}

void	print_hex_string(char *string, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 40;
	while (i < len)
	{
		decimal_to_hex((unsigned char)string[i], 2);
		count -= 2;
		i++;
		if (i % 2 == 0)
		{
			write(1, " ", 1);
			count -= 1;
		}
	}
	while (count > 0)
	{
		count--;
		write(1, " ", 1);
	}
}

void	print(char *string, int len)
{
	int	i;

	write(1, ": ", 2);
	print_hex_string(string, len);
	i = 0;
	while (i < len)
	{
		if (' ' <= string[i] && string[i] <= '~')
			write(1, &string[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			string[17];
	char			*address;

	i = 0;
	address = addr;
	string[16] = '\0';
	while (i < size)
	{
		if (i % 16 == 0)
			decimal_to_hex((unsigned long long)&address[i], 16);
		string[i % 16] = address[i];
		if (i % 16 == 15)
			print(string, 16);
		i++;
	}
	if (i % 16 != 0)
		print(string, i % 16);
	return (addr);
}
