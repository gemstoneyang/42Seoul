/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:42:07 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/19 17:39:31 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	arr_check(char arr[], int depth, int num)
{
	int	i;

	if (depth == 0)
		return (0);
	i = 0;
	while (i <= depth - 1)
	{
		if (arr[i] >= num + 48)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	func(char arr[], int n, int depth)
{
	int		i;
	char	c;

	if (n <= depth)
	{
		write(1, arr, n);
		if (arr[0] >= 10 - n + 48)
			return ;
		write(1, ", ", 2);
		return ;
	}
	i = 0;
	while (i <= 9)
	{
		if (arr_check(arr, depth, i) == 1)
		{
			i++;
			continue ;
		}
		c = i + 48;
		arr[depth] = c;
		func(arr, n, depth + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	func(arr, n, 0);
}
