/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:00:18 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/09 22:04:43 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
	t_list *node;

	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
