/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:22:17 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/01 20:58:36 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_length(char *str, int mode)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (mode == 0)
	{
		while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
			i++;
		return (i);
	}
	else
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

int	base_to_int(int res, char c, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
		{
			res *= count_length(base, 1);
			j = 0;
			while (base[i] != '\0')
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

int	count_nbr(long long nbr, int n)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		count++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= n;
		count++;
	}
	return (count);
}

void	print_base(long long n, char *base, long long len, char *result)
{
	if (n / len == 0)
	{
		*result = base[n % len];
		return ;
	}
	print_base(n / len, base, len, result - 1);
	*result = base[n % len];
	return ;
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long long	n;
	char		*result;
	int			nbr_len;

	nbr_len = count_nbr((long long)nbr, count_length(base, 1));
	result = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!result)
		return (result);
	result[nbr_len] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		n = -nbr;
		print_base(n, base, count_length(base, 1), (result + (nbr_len - 1)));
	}
	else
	{
		n = nbr;
		print_base(n, base, count_length(base, 1), (result + (nbr_len - 1)));
	}
	return (result);
}
