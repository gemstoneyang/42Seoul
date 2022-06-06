/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:08:35 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:11:23 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one_argument.h"

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

int	ft_atoi_yang(char *string, int start, int end)
{
	int	i;
	int	res;

	res = 0;
	i = start;
	while (i <= end)
	{
		res *= 10;
		res += string[i] - '0';
		i++;
	}
	return (res);
}

void	print_string(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
	write(1, " ", 1);
}

char	*return_value(int num, t_dict *t_head)
{
	while (t_head->next)
	{
		if (t_head->key == num)
			return (t_head->value);
		t_head = t_head->next;
	}
	return (0);
}

void	print_number(int n, t_dict *t_head)
{
	if (n == 0)
		return ;
	if (n / 100)
	{
		print_string(return_value(n / 100, t_head));
		print_string(return_value(100, t_head));
	}
	if (n % 100 == 0)
		return ;
	if (n % 100 < 20)
	{
		print_string(return_value(n % 100, t_head));
	}
	else
	{
		print_string(return_value((n % 100) / 10 * 10, t_head));
		if (n % 10 != 0)
		{
			print_string(return_value(n % 10, t_head));
		}
	}
}

void	print_digit(int n, t_digit_dict *t_digit_head)
{
	while (t_digit_head)
	{
		if (t_digit_head->digit == n)
		{
			print_string(t_digit_head->value);
			write(1, " ", 1);
			return ;
		}
		t_digit_head = t_digit_head->next;
	}
}

void	convert_string(char *string, t_dict *t_head, t_digit_dict *t_digit_head)
{
	int	len;
	int	start;
	int	end;
	int	n;

	len = ft_strlen(string);
	if (len % 3 == 0)
		end = 2;
	else if (len % 3 == 1)
		end = 0;
	else
		end = 1;
	start = 0;
	while (end < len)
	{
		n = ft_atoi_yang(string, start, end);
		print_number(n, t_head);
		if (n != 0)
			print_digit(len - end, t_digit_head);
		start = end + 1;
		end += 3;
	}
	write(1, "\n", 1);
}
