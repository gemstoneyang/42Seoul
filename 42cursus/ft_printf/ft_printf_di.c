/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:47:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/28 21:53:37 by wonyang          ###   ########.fr       */
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

int	print_di_num(int val_int)
{
	int		i;
	char	*str;

	str = ft_itoa(val_int);
	i = 0;
	if (val_int < 0)
		i++;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	free(str);
	if (val_int < 0)
		i--;
	return (i);
}

int	print_di_space(t_info *info, int val_int)
{
	int		i;
	char	*str;
	int		str_len;

	if (info->zero == True)
		return (0);
	i = 0;
	str = ft_itoa(val_int);
	str_len = ft_strlen(str);
	free(str);
	if (info->plus == True || info->space == True)
		i++;
	if (val_int >= 0 && (info->plus == True || info->space == True))
		i++;
	while (i < info->width - str_len)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	print_di_zero(t_info *info, int val_int)
{
	int		i;
	char	*str;
	int		str_len;

	if (info->zero == False)
		return (0);
	i = 0;
	str = ft_itoa(val_int);
	str_len = ft_strlen(str);
	free(str);
	if (info->plus == True || info->space == True)
		i++;
	if (val_int >= 0 && (info->plus == True || info->space == True))
		i++;
	while (i < info->width - str_len)
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
		total_size += print_di_num(val_int);
		total_size += print_di_space(info, val_int);
	}
	else
	{
		total_size += print_di_space(info, val_int);
		total_size += print_di_sign(info, val_int);
		total_size += print_di_zero(info, val_int);
		total_size += print_di_num(val_int);
	}
	return (total_size);
}
