/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:23:37 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/01 09:30:57 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_s(t_info *info, char *val_str)
{
	int	str_len;

	str_len = ft_strlen(val_str);
	if (info->period == TRUE && info->precision < str_len)
		return (info->precision);
	return (str_len);
}

int	print_s_space(t_info *info, char *val_str)
{
	int	i;
	int	str_len;

	i = 0;
	if (val_str == NULL)
		val_str = "(null)";
	str_len = ft_strlen_s(info, val_str);
	while (i < info->width - str_len)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	print_s_str(t_info *info, char *val_str)
{
	int	i;

	if (val_str == NULL)
		val_str = "(null)";
	i = -1;
	if (info->period == TRUE)
		while (++i < info->precision && val_str[i])
			write(1, val_str + i, 1);
	else
		while (val_str[++i])
			write(1, val_str + i, 1);
	return (i);
}

int	print_info_s(t_info *info, va_list ap)
{
	int		total_size;
	char	*val_str;

	total_size = 0;
	val_str = va_arg(ap, char *);
	if (info->minus == TRUE)
	{
		total_size += print_s_str(info, val_str);
		total_size += print_s_space(info, val_str);
	}
	else
	{
		total_size += print_s_space(info, val_str);
		total_size += print_s_str(info, val_str);
	}
	return (total_size);
}
