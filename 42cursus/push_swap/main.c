/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:04:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/10 13:38:08 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_node(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->prev = NULL;
	node->next = NULL;
	node->value = val;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->bot = NULL;
	stack->count = 0;
	return (stack);
}

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

#include <stdio.h>

void	parse_nums(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		j = 0;
		while (arr[j])
		{
			pushleft(stack, init_node(ft_atoi(arr[j])));
			j++;
		}
		i++;
		free_arr(arr);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	//t_stack	*stack_b;

	stack_a = init_stack();
	//stack_b = init_stack();
	parse_nums(argc, argv, stack_a);
	t_node	*head = stack_a->top;
	while (head)
	{
		printf("%d\n", head->value);
		head = head->next;
	}
	return (0);
}
