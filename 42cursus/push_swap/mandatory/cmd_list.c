/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:15:36 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 18:07:05 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_bool	cmd_change(t_list *now_node, char *cmd_a, char *cmd_b, char *cmd_c)
{	
	t_list	*next_node;
	char	*now_cmd;
	char	*next_cmd;
	t_list	*tmp;

	next_node = now_node->next;
	now_cmd = (char *)(now_node->content);
	next_cmd = (char *)(next_node->content);
	if ((ft_strcmp(now_cmd, cmd_a) == 0 && ft_strcmp(next_cmd, cmd_b) == 0) || \
			(ft_strcmp(now_cmd, cmd_b) == 0 && ft_strcmp(next_cmd, cmd_a) == 0))
	{
		now_node->content = (void *)cmd_c;
		tmp = next_node;
		next_node = next_node->next;
		now_node->next = next_node;
		free(tmp);
		return (TRUE);
	}
	return (FALSE);
}

void	cmd_optimization(t_data *data)
{
	t_list	*node;

	if (data->cmd_list == NULL || data->cmd_list->next == NULL)
		return ;
	node = data->cmd_list->next;
	while (node->next)
	{
		if (cmd_change(node, "ra", "rb", "rr"))
			continue ;
		else if (cmd_change(node, "rra", "rrb", "rrr"))
			continue ;
		else if (cmd_change(node, "sa", "sb", "ss"))
			continue ;
		else if (cmd_change(node, "sa", "ss", "sb"))
			continue ;
		else if (cmd_change(node, "sb", "ss", "sa"))
			continue ;
		else if (cmd_change(node, "ra", "rrr", "rrb"))
			continue ;
		else if (cmd_change(node, "rb", "rrr", "rra"))
			continue ;
		else if (cmd_change(node, "rra", "rr", "rb"))
			continue ;
		else if (cmd_change(node, "rrb", "rr", "ra"))
			continue ;
		else
			node = node->next;
	}
}

void	add_cmd(t_data *data, char *cmd)
{
	t_list	*node;
	t_list	*list;

	list = data->cmd_list;
	node = ft_lstnew((void *)cmd);
	if (!node)
		error_exit(data);
	ft_lstadd_back(&list, node);
}

void	write_cmd(void *cmd)
{
	printf("%s\n", (char *)cmd);
}

void	print_cmd(t_data *data)
{
	t_list	*node;

	node = data->cmd_list;
	if (node)
		node = node->next;
	ft_lstiter(node, write_cmd);
}
