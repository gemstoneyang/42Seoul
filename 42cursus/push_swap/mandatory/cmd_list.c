/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:15:36 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 14:46:44 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
