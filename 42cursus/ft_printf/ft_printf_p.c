/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:59:00 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/01 18:24:41 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p_0x(void)
{
	write(1, "0x", 2);
	return (2);
}

int	print_p_num(t_info *info, uintptr_t val_int)
{
	int		i;
	int		j;
	int		num_len;

	num_len = ft_count_length_p(val_int);
	i = -1;
	while (++i < info->precision - num_len)
		write(1, "0", 1);
	if (info->period == TRUE && info->precision == 0 && val_int == 0)
		return (i);
	j = ft_decimal_to_hex_p(val_int);
	return (i + j);
}

int	print_p_space(t_info *info, uintptr_t val_int)
{
	int	i;
	int	num_len;

	if (info->period == FALSE && info->zero == TRUE)
		return (0);
	i = 0;
	num_len = ft_numlen_p(info, val_int);
	while (i < ft_blank_size_p(info, num_len))
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	print_p_zero(t_info *info, uintptr_t val_int)
{
	int	i;
	int	num_len;

	if (info->period == TRUE || info->zero == FALSE)
		return (0);
	i = 0;
	num_len = ft_count_length_p(val_int);
	while (i < ft_blank_size_p(info, num_len))
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int	print_info_p(t_info *info, va_list ap)
{
	int			total_size;
	uintptr_t	val_int;

	total_size = 0;
	val_int = va_arg(ap, uintptr_t);
	if (info->minus == TRUE)
	{
		total_size += print_p_0x();
		total_size += print_p_num(info, val_int);
		total_size += print_p_space(info, val_int);
	}
	else
	{
		total_size += print_p_space(info, val_int);
		total_size += print_p_0x();
		total_size += print_p_zero(info, val_int);
		total_size += print_p_num(info, val_int);
	}
	return (total_size);
}
