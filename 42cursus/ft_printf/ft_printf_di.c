/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:47:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/31 18:04:36 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_di_sign(t_info *info, int val_int)
{
	if (info->plus == FALSE && info->space == FALSE && val_int >= 0)
		return (0);
	if (val_int >= 0)
	{
		if (info->plus == TRUE)
			write(1, "+", 1);
		else if (info->space == TRUE)
			write(1, " ", 1);
	}
	else
		write(1, "-", 1);
	return (1);
}

int	print_di_num(t_info *info, int val_int)
{
	int		i;
	int		j;
	int		num_len;
	char	*str;

	num_len = ft_absnumlen_di(info, val_int);
	i = -1;
	while (++i < info->precision - num_len)
		write(1, "0", 1);
	if (info->period == TRUE && info->precision == 0 && val_int == 0)
		return (i);
	j = 0;
	if (val_int < 0)
		j++;
	str = ft_itoa(val_int);
	while (str[j])
	{
		write(1, str + j, 1);
		j++;
	}
	free(str);
	if (val_int < 0)
		j--;
	return (i + j);
}

int	print_di_space(t_info *info, int val_int)
{
	int	i;
	int	num_len;

	if (info->period == FALSE && info->zero == TRUE)
		return (0);
	i = 0;
	num_len = ft_absnumlen_di(info, val_int);
	while (i < ft_blank_size_di(info, num_len, val_int))
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	print_di_zero(t_info *info, int val_int)
{
	int	i;
	int	num_len;

	if (info->period == TRUE || info->zero == FALSE)
		return (0);
	i = 0;
	num_len = ft_absnumlen_di(info, val_int);
	while (i < ft_blank_size_di(info, num_len, val_int))
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int	print_info_di(t_info *info, va_list ap)
{
	int	total_size;
	int	val_int;

	total_size = 0;
	val_int = va_arg(ap, int);
	if (info->minus == TRUE)
	{
		total_size += print_di_sign(info, val_int);
		total_size += print_di_num(info, val_int);
		total_size += print_di_space(info, val_int);
	}
	else
	{
		total_size += print_di_space(info, val_int);
		total_size += print_di_sign(info, val_int);
		total_size += print_di_zero(info, val_int);
		total_size += print_di_num(info, val_int);
	}
	return (total_size);
}
