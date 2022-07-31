/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 02:55:46 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/31 17:57:21 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_absnumlen_di(t_info *info, int num)
{
	char	*str;
	int		num_len;

	if (num == 0 && info->period == TRUE && info->precision == 0)
		return (0);
	str = ft_itoa(num);
	num_len = ft_strlen(str);
	free(str);
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
