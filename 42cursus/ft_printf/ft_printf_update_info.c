/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_update_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:30:23 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/23 18:30:36 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	update_info_flag(char flag, t_info *info)
{
	if (flag == '-')
		info->minus = True;
	else if (flag == '+')
		info->plus = True;
	else if (flag == ' ')
		info->space = True;
	else if (flag == '0')
		info->zero = True;
	else if (flag == '#')
		info->hash = True;
}

void	update_info_width(char n, t_info *info)
{
	info->width *= 10;
	info->width += n - '0';
}

void	update_info_precision(char n, t_info *info)
{
	info->precision *= 10;
	info->precision += n - '0';
}
