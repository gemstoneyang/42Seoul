/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 02:55:46 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/31 03:00:54 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_absnumlen(int num)
{
	char	*str;
	int		num_len;

	str = ft_itoa(num);
	num_len = ft_strlen(str);
	free(str);
	if (num >= 0)
		return (num_len);
	return (num_len - 1);
}

int	ft_blank_size(t_info *info, int num_len)
{
	if (info->precision <= num_len)
		return (info->width - num_len);
	return (info->width - info->precision);
}
