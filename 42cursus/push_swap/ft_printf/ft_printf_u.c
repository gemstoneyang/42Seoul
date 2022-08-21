/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:14:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/09 13:30:39 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u_num(t_info *info, unsigned int val_int)
{
	int		i;
	int		j;
	int		num_len;
	char	*str;

	num_len = ft_absnumlen_u(info, val_int);
	i = -1;
	while (++i < info->precision - num_len)
		write(1, "0", 1);
	if (info->period == TRUE && info->precision == 0 && val_int == 0)
		return (i);
	j = -1;
	str = ft_itoa_u(val_int);
	if (!str)
		return (i);
	while (str[++j])
		write(1, str + j, 1);
	free(str);
	if (val_int < 0)
		j--;
	return (i + j);
}

int	print_u_space(t_info *info, unsigned int val_int)
{
	int		i;
	int		num_len;

	if (info->period == FALSE && info->zero == TRUE)
		return (0);
	i = 0;
	num_len = ft_absnumlen_u(info, val_int);
	while (i < ft_blank_size_u(info, num_len))
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	print_u_zero(t_info *info, unsigned int val_int)
{
	int		i;
	int		num_len;

	if (info->period == TRUE || info->zero == FALSE)
		return (0);
	i = 0;
	num_len = ft_absnumlen_u(info, val_int);
	while (i < ft_blank_size_u(info, num_len))
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int	print_info_u(t_info *info, va_list ap)
{
	int				total_size;
	unsigned int	val_int;

	total_size = 0;
	val_int = va_arg(ap, unsigned int);
	if (info->minus == TRUE)
	{
		total_size += print_u_num(info, val_int);
		total_size += print_u_space(info, val_int);
	}
	else
	{
		total_size += print_u_space(info, val_int);
		total_size += print_u_zero(info, val_int);
		total_size += print_u_num(info, val_int);
	}
	return (total_size);
}
