/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:03:50 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/31 19:34:07 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c_space(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->width - 1)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	print_c_char(char val_char)
{
	write(1, &val_char, 1);
	return (1);
}

int	print_info_c(t_info *info, va_list ap)
{
	int	total_size;
	int	val_char;

	total_size = 0;
	val_char = va_arg(ap, int);
	if (info->minus == TRUE)
	{
		total_size += print_c_char(val_char);
		total_size += print_c_space(info);
	}
	else
	{
		total_size += print_c_space(info);
		total_size += print_c_char(val_char);
	}
	return (total_size);
}
