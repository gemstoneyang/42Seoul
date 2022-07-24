/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:47:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/25 02:53:56 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_info_di(t_info *info, va_list ap)
{
	int	return_size;
	char	*num;

	num = ft_itoa(va_arg(ap, int));
	return_size = ft_strlen(num);
	ft_putstr_fd(num, 1);
	free(num);
	return (return_size);
}
