/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:04:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/05 02:22:41 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_node(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node *));
	node->prev = NULL;
	node->next = NULL;
	node->value = val;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack *));
	stack->top = NULL;
	stack->bot = NULL;
	stack->count = 0;
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	char	**arr;

	stack_a = init_stack();
	stack_b = init_stack();
	i = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		while (arr
		i++;
	}
	return (0);
}
