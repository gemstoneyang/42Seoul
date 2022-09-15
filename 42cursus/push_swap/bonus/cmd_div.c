/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:51:09 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/15 21:45:50 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	cmd_div(char *cmd, t_data *data)
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
	else
		return (ERROR);
	return (SUCCESS);
}

int	cmd(char *str, t_data *data)
{
	if (cmd_div(str, data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
