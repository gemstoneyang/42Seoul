/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:27:48 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/16 22:55:56 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr)
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

int	is_integer(char *str)
{
	int		n;
	int		result;
	char	*res;

	result = 1;
	n = ft_atoi(str);
	res = ft_itoa(n);
	if (!res)
		return (0);
	if (ft_strncmp(str, res, ft_strlen(str)) != 0)
		result = 0;
	free(res);
	return (result);
}

void	add_num(char *str, t_data *data)
{
	int		i;
	char	**arr;
	t_node	*node;
	int		n;

	arr = ft_split(str, ' ');
	if (!arr)
		error_exit(data);
	i = 0;
	while (arr[i])
	{
		if (is_integer(arr[i]) == 0)
		{
			free_arr(arr);
			error_exit(data);
		}
		n = ft_atoi(arr[i]);
		node = init_node(n);
		if (!node)
		{
			free_arr(arr);
			error_exit(data);
		}
		pushleft(data->stack_a, node);
		i++;
	}
	free_arr(arr);
}

void	parse_nums(int argc, char **argv, t_data *data)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		add_num(argv[i], data);
		i++;
	}
}

