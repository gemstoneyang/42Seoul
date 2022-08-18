/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:27:48 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/18 22:45:02 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_num(char *str, t_data *data)
{
	int		i;
	char	**arr;
	t_node	*node;

	arr = ft_split(str, ' ');
	if (!arr)
		error_exit(data);
	i = 0;
	while (arr[i])
	{
		node = init_node(arr[i]);
		if (!node)
		{
			free_split(arr);
			error_exit(data);
		}
		pushleft(data->stack_a, node);
		i++;
	}
	free_split(arr);
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
