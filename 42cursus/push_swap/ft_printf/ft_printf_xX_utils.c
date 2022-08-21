/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:00:47 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/01 17:16:25 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen_xx(t_info *info, unsigned int num)
{
	if (num == 0 && info->period == TRUE && info->precision == 0)
		return (0);
	return (ft_count_length_xx(num));
}

int	ft_blank_size_xx(t_info *info, int num_len, unsigned int val_int)
{
	if (info->precision <= num_len)
	{
		if (info->hash == TRUE && val_int != 0)
			return (info->width - num_len - 2);
		return (info->width - num_len);
	}
	if (info->hash == TRUE && val_int != 0)
		return (info->width - info->precision - 2);
	return (info->width - info->precision);
}

int	ft_count_length_xx(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_decimal_to_hex_xx(t_info *info, unsigned int decimal)
{
	int		len;
	int		idx;
	int		mod;
	char	hexdecimal[16];

	if (decimal == 0)
		return (write(1, "0", 1));
	len = ft_count_length_xx(decimal);
	idx = ft_count_length_xx(decimal) - 1;
	while (decimal > 0)
	{
		mod = decimal % 16;
		if (mod < 10)
			hexdecimal[idx] = '0' + mod;
		else
		{
			if (info->type == 'x')
				hexdecimal[idx] = 'a' + (mod - 10);
			else
				hexdecimal[idx] = 'A' + (mod - 10);
		}
		decimal /= 16;
		idx--;
	}
	return (write(1, hexdecimal, len));
}
