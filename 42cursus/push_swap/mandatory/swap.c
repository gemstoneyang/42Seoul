/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:24:00 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/18 17:28:03 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	}
}
