/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:59:07 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/01 18:24:09 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen_p(t_info *info, uintptr_t num)
{
	if (num == 0 && info->period == TRUE && info->precision == 0)
		return (0);
	return (ft_count_length_p(num));
}

int	ft_blank_size_p(t_info *info, int num_len)
{
	if (info->precision <= num_len)
		return (info->width - num_len - 2);
	return (info->width - info->precision - 2);
}

int	ft_count_length_p(uintptr_t n)
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

int	ft_decimal_to_hex_p(uintptr_t decimal)
{
	int		len;
	int		idx;
	int		mod;
	char	hexdecimal[16];

	if (decimal == 0)
		return (write(1, "0", 1));
	len = ft_count_length_p(decimal);
	idx = ft_count_length_p(decimal) - 1;
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
	return (write(1, hexdecimal, len));
}
