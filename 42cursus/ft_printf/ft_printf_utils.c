/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:30:52 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/23 18:49:54 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (True);
	return (False);
}

t_bool	ft_isspecifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (True);
	return (False);
}

t_info	*new_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->type = '\0';
	info->minus = False;
	info->plus = False;
	info->space = False;
	info->zero = False;
	info->hash = False;
	info->period = False;
	info->width = 0;
	info->precision = 0;
	return (info);
}
