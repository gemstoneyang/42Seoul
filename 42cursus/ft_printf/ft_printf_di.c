/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:47:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/31 03:00:54 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_di_sign(t_info *info, int val_int)
{
	if (info->plus == False && info->space == False && val_int >= 0)
		return (0);
	if (val_int >= 0)
	{
		if (info->plus == True)
			write(1, "+", 1);
		else if (info->space == True)
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

	str = ft_itoa(val_int);
	num_len = ft_absnumlen(val_int);
	i = 0;
	while (i < info->precision - num_len)
	{
		write(1, "0", 1);
		i++;
	}
	j = 0;
	if (val_int < 0)
		j++;
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
	int		i;
	int		num_len;

	if (info->zero == True)
		return (0);
	i = 0;
	num_len = ft_absnumlen(val_int);
	if (info->plus == True || info->space == True || val_int < 0)
		num_len++;
	while (i < ft_blank_size(info, num_len))
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	print_di_zero(t_info *info, int val_int)
{
	int		i;
	int		num_len;

	if (info->zero == False)
		return (0);
	i = 0;
	num_len = ft_absnumlen(val_int);
	if (info->plus == True || info->space == True || val_int < 0)
		num_len++;
	while (i < ft_blank_size(info, num_len))
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int	print_info_di(t_info *info, va_list ap)
{
	int		total_size;
	int		val_int;

	total_size = 0;
	val_int = va_arg(ap, int);
	if (info->minus == True)
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
