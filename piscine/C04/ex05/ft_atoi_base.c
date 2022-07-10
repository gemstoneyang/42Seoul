/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:05:13 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/26 10:51:39 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_length(char *str, int mode)
{
	int	i;

	i = 0;
	if (mode == 0)
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i++;
		return (i);
	}
	else
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
}

int	check_same_char(char c, char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == c)
			return (1);
		i++;
	}
	arr[i] = c;
	return (0);
}

int	is_exception(char *base)
{
	int		i;
	char	arr[300];

	i = 0;
	while (i < 300)
	{
		arr[i] = '\0';
		i++;
	}
	if (count_length(base, 1) <= 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || count_length(base, 0) != 0)
			return (1);
		if (check_same_char(base[i], arr) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	base_to_int(int res, char c, char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
		{
			res *= count_length(base, 1);
			j = 0;
			while (base[j] != '\0')
			{
				if (base[j] == c)
					return (res + j);
				j++;
			}
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = count_length(str, 0);
	if (is_exception(base) == 1)
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && base_to_int(res, str[i], base) != -1)
	{
		res = base_to_int(res, str[i], base);
		i++;
	}
	return (sign * res);
}
