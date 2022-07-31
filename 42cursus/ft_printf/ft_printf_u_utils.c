/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:16:58 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/31 17:35:03 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_length_u(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_u(unsigned int n)
{
	size_t	i;
	size_t	len;
	char	*res;
	long	num;

	num = (long)n;
	len = ft_count_length_u(num);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = len - 1;
	if (num == 0)
		res[0] = '0';
	while (num)
	{
		res[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (res);
}

int	ft_absnumlen_u(t_info *info, unsigned int num)
{
	if (num == 0 && info->period == TRUE && info->precision == 0)
		return (0);
	return (ft_count_length_u(num));
}

int	ft_blank_size_u(t_info *info, int num_len)
{
	if (info->precision <= num_len)
		return (info->width - num_len);
	return (info->width - info->precision);
}
