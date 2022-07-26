/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:47:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/26 04:28:03 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_info_di(t_info *info, va_list ap)
{
	int		return_size;
	int		ap_int;
	char	*num;

	ap_int = va_arg(ap, int);
	num = ft_itoa(ap_int);
	return_size = ft_strlen(num);
	ft_putstr_fd(num, 1);
	free(num);
	return (return_size);
}
