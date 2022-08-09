/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:30:52 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/09 13:10:52 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_isspecifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (TRUE);
	return (FALSE);
}

t_info	*new_info(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->type = '\0';
	info->minus = FALSE;
	info->plus = FALSE;
	info->space = FALSE;
	info->zero = FALSE;
	info->hash = FALSE;
	info->period = FALSE;
	info->width = 0;
	info->precision = 0;
	return (info);
}
