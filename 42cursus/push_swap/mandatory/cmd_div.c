/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:51:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/18 22:51:10 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_div(char *cmd, t_data *data)
{
	if (ft_strcmp(cmd, "sa") == 0)
		sa(data);
	else if (ft_strcmp(cmd, "sb") == 0)
		sb(data);
	else if (ft_strcmp(cmd, "ss") == 0)
		ss(data);
	else if (ft_strcmp(cmd, "pa") == 0)
		pa(data);
	else if (ft_strcmp(cmd, "pb") == 0)
		pb(data);
	else if (ft_strcmp(cmd, "ra") == 0)
		ra(data);
	else if (ft_strcmp(cmd, "rb") == 0)
		rb(data);
	else if (ft_strcmp(cmd, "rr") == 0)
		rr(data);
	else if (ft_strcmp(cmd, "rra") == 0)
		rra(data);
	else if (ft_strcmp(cmd, "rrb") == 0)
		rrb(data);
	else if (ft_strcmp(cmd, "rrr") == 0)
		rrr(data);
}

void	cmd(char *str, t_data *data)
{
	char	**cmd_list;
	int		i;

	cmd_list = ft_split(str, ' ');
	if (cmd_list == NULL)
		error_exit(data);
	i = 0;
	while (cmd_list[i])
	{
		cmd_div(cmd_list[i], data);
		i++;
	}
	free_split(cmd_list);
}
