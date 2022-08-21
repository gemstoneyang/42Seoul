/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 02:55:46 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/09 13:24:56 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_length_di(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_absnumlen_di(t_info *info, int num)
{
	int		num_len;

	if (num == 0 && info->period == TRUE && info->precision == 0)
		return (0);
	num_len = ft_count_length_di(num);
	if (num >= 0)
		return (num_len);
	return (num_len - 1);
}

int	ft_blank_size_di(t_info *info, int num_len, int val_int)
{
	if (info->precision <= num_len)
	{
		if (info->plus == TRUE || info->space == TRUE || val_int < 0)
			return (info->width - num_len - 1);
		return (info->width - num_len);
	}
	if (info->plus == TRUE || info->space == TRUE || val_int < 0)
		return (info->width - info->precision - 1);
	return (info->width - info->precision);
}
