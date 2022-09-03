/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:27:48 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/03 18:26:08 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*init_node(char *str)
{
	t_node	*node;

	if (is_integer(str) == FALSE)
		return (NULL);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->value = ft_atoi(str);
	return (node);
}

static void	add_num(char *str, t_data *data)
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
