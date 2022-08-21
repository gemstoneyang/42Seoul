/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:38:16 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/01 17:16:37 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_xx_hash(t_info *info, unsigned int val_int)
{
	if (info->hash == FALSE || val_int == 0)
		return (0);
	if (info->type == 'x')
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
	return (2);
}

int	print_xx_num(t_info *info, unsigned int val_int)
{
	int		i;
	int		j;
	int		num_len;

	num_len = ft_count_length_xx(val_int);
	i = -1;
	while (++i < info->precision - num_len)
		write(1, "0", 1);
	if (info->period == TRUE && info->precision == 0 && val_int == 0)
		return (i);
	j = ft_decimal_to_hex_xx(info, val_int);
	return (i + j);
}

int	print_xx_space(t_info *info, unsigned int val_int)
{
	int	i;
	int	num_len;

	if (info->period == FALSE && info->zero == TRUE)
		return (0);
	i = 0;
	num_len = ft_numlen_xx(info, val_int);
	while (i < ft_blank_size_xx(info, num_len, val_int))
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	print_xx_zero(t_info *info, unsigned int val_int)
{
	int	i;
	int	num_len;

	if (info->period == TRUE || info->zero == FALSE)
		return (0);
	i = 0;
	num_len = ft_count_length_xx(val_int);
	while (i < ft_blank_size_xx(info, num_len, val_int))
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int	print_info_xx(t_info *info, va_list ap)
{
	int	total_size;
	int	val_int;

	total_size = 0;
	val_int = va_arg(ap, unsigned int);
	if (info->minus == TRUE)
	{
		total_size += print_xx_hash(info, val_int);
		total_size += print_xx_num(info, val_int);
		total_size += print_xx_space(info, val_int);
	}
	else
	{
		total_size += print_xx_space(info, val_int);
		total_size += print_xx_hash(info, val_int);
		total_size += print_xx_zero(info, val_int);
		total_size += print_xx_num(info, val_int);
	}
	return (total_size);
}
