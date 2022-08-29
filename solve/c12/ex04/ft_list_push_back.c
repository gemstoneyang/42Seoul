/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:05:06 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/09 22:11:29 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*node;
	t_list *tmp;

	tmp = *begin_list;
	node = ft_create_elem(data);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}
