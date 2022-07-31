/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:23:37 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/31 19:47:22 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s_str(t_info *info, char *val_str)
{
	int	i;

	i = 0;
	while (info->period == True && i < info->precision == 0)
}

int	print_info_s(t_info *info, va_list ap)
{
	int		total_size;
	char	*val_str;

	total_size = 0;
	val_str= va_arg(ap, char *);
	if (info->minus == TRUE)
	{
		total_size += print_s_str(info, val_str);
		total_size += print_s_space(info, val_str);
	}
	else
	{
		total_size += print_s_space(info, val_str);
		total_size += print_s_zero(info, val_str);
		total_size += print_s_str(info, val_str);
	}
}
