/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:28:29 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/26 18:32:21 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

static size_t	count_length(long n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*dst;
	size_t			i;
	void			*p;

	p = malloc(num * size);
	if (!p)
		return (p);
	dst = (unsigned char *)p;
	i = 0;
	while (i < num * size)
	{
		*dst = 0;
		dst++;
		i++;
	}
	return (p);
}

static char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	char	*res;
	long	num;

	num = (long)n;
	len = count_length(num);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (res);
	i = len - 1;
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
	}
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

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != '\0')
		return (s1[i]);
	if (s2[i] != '\0')
		return (-s2[i]);
	return (0);
}

int	ft_isinteger(char *str)
{
	int		n;
	char	*res;

	n = ft_atoi(str);
	res = ft_itoa(n);
	if (!res)
		return (0);
	if (*str == '+' || (*str == '-' && n == 0))
		str++;
	if (ft_strcmp(str, res) != 0)
	{
		free(res);
		return (0);
	}
	free(res);
	return (1);
}
