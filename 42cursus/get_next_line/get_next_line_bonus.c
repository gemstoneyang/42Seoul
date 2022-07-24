/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:44:23 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/24 21:56:51 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_make_node(int fd)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node->fd = fd;
	node->prev = NULL;
	node->next = NULL;
	node->cache = NULL;
	return (node);
}

t_list	*ft_find_node(t_list **list, int fd)
{
	t_list	*node;
	t_list	*new_node;

	if (*list == NULL)
	{
		*list = ft_make_node(fd);
		return (*list);
	}
	node = *list;
	while (node->next)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	if (node->fd == fd)
		return (node);
	new_node = ft_make_node(fd);
	node->next = new_node;
	new_node->prev = node;
	return (new_node);
}

void	ft_del_node(t_list **list, int fd)
{
	t_list	*node;

	node = ft_find_node(list, fd);
	if (node->cache)
		return ;
	if ((*list)->fd == node->fd)
		*list = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	free(node);
	node = NULL;
}

char	*ft_read_file(int fd, char *cache)
{
	char	*buffer;
	ssize_t	read_byte;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (!ft_strchr(cache, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(cache);
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		cache = ft_strjoin(cache, buffer);
	}
	free(buffer);
	return (cache);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*node;
	char			*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	node = ft_find_node(&list, fd);
	node->cache = ft_read_file(fd, node->cache);
	if (!node->cache)
	{
		ft_del_node(&list, fd);
		return (NULL);
	}
	result = ft_get_line(node->cache);
	node->cache = ft_update_cache(node->cache);
	ft_del_node(&list, fd);
	return (result);
}
