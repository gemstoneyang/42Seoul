/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:26:08 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/08 23:35:26 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

int	min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a + 1);
		else
			return (c + 1);
	}
	else
	{
		if (b < c)
			return (b + 1);
		else
			return (c + 1);
	}
}
