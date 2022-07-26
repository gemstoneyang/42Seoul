/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_persent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:21:08 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/26 22:55:48 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_persent_blank(t_info *info)
{
	int	i;

	i = 0;
	if (info->zero == True && info->minus == False)
		while (++i < info->width)
			write(1, "0", 1);
	else
		while (++i < info->width)
			write(1, " ", 1);
	return (i - 1);
}

int	print_info_persent(t_info *info)
{
	int	total_size;

	total_size = 1;
	if (info->minus == True)
	{
		write(1, "%", 1);
		total_size += print_persent_blank(info);
	}
	else
	{
		total_size += print_persent_blank(info);
		write(1, "%", 1);
	}
	return (total_size);
}
