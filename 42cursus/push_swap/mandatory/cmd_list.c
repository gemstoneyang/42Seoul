/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 02:15:36 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/21 02:45:55 by wonyang          ###   ########.fr       */
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
	printf("test\n");
	printf("%s\n", (char *)cmd);
}

void	print_cmd(t_data *data)
{
	t_list	*list;
	list = data->cmd_list;
	write_cmd(list->content);
	ft_lstiter(data->cmd_list, write_cmd);
}
