/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:12:43 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 21:05:46 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	format_validation(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-' || ('0' <= str[i] && str[i] <= '9'))
		i++;
	else
		return (FALSE);
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// todo
int	string_to_int(char *input)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (input[i] != '\0')
	{
		if (res > 214748364 && input[i] - '0' >= 8)
			return (-1);
		res *= 10;
		res += input[i] - '0';
		i++;
	}
	return (res);
}

t_bool	is_integer(char *str)
{
	int		n;
	char	*res;

	n = ft_atoi(str);
	res = ft_itoa(n);
	if (!res)
		return (FALSE);
	if (ft_strcmp(str, res) != 0)
	{
		free(res);
		return (FALSE);
	}
	free(res);
	return (TRUE);
}

int	ft_strcmp(char *s1, char *s2)
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

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
