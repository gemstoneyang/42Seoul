/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:13:55 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/09 22:22:55 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

t_list *ft_list_push_strs(int size, char **strs)
{
	t_list *start;
	t_list *tmp;
	int	i;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		start = ft_create_elem(strs[i]);
		start->next = tmp;
		tmp = start;
		i++;
	}
	return (tmp);
}
