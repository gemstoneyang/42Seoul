/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:15:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/20 18:58:54 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_new_line_sub(t_list **cache, char buffer[], char *nxt_chr, int fd)
{
	char	*tmp;
	char	*result;
	t_list	*node;

	node = find_node(cache, fd);
	tmp = ft_strndup(buffer, nxt_chr - buffer + 1);
	if (!tmp)
		return (NULL);
	result = ft_strjoin(node->value, tmp);
	free(tmp);
	if (!result)
		return (NULL);
	if (*(nxt_chr + 1) == '\0')
		del_node(cache, fd);
	else
	{
		node->value = ft_strndup(nxt_chr + 1, ft_strlen(nxt_chr + 1));
		if (!(node->value))
		{
			free(result);
			return (NULL);
		}
	}
	return (result);
}

int	make_new_line(t_list **cache, char buffer[], char **result, int fd)
{
	char	*tmp;
	t_list	*node;

	node = find_node(cache, fd);
	if (node->value == NULL)
	{
		node->value = ft_strndup("", 0);
		if (node->value == NULL)
		{
			*result = NULL;
			return (1);
		}
	}
	if (ft_strchr(buffer, '\n') == NULL)
	{
		tmp = node->value;
		node->value = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!(node->value))
		{
			*result = NULL;
			return (1);
		}
		return (0);
	}
	*result = make_new_line_sub(cache, buffer, ft_strchr(buffer, '\n'), fd);
	return (1);
}

char	*low_read(t_list **cache, char buffer[], int fd)
{
	char	*result;
	t_list	*node;

	node = find_node(cache, fd);
	if (ft_strlen(buffer) == 0)
	{
		if (node->value == NULL)
		{
			del_node(cache, fd);
			return (NULL);
		}
		result = ft_strndup(node->value, ft_strlen(node->value));
		del_node(cache, fd);
		if (!result)
			return (NULL);
		return (result);
	}
	if (make_new_line(cache, buffer, &result, fd) == 0)
	{
		result = node->value;
		del_node(cache, fd);
	}
	return (result);
}

void	del_node(t_list **cache, int fd)
{
	t_list	*node;

	node = find_node(cache, fd);
	if ((*cache)->fd == node->fd)
	{
		if (node->next)
			node->next->prev = NULL;
		*cache = node->next;
		free(node->value);
		free(node);
		return ;
	}
	while (node)
	{
		if (node->fd == fd)
		{
			if (node->next)
				node->next->prev = node->prev;
			node->prev->next = node->next;
			free(node->value);
			free(node);
			return ;
		}
		node = node->next;
	}
}

t_list	*find_node(t_list **cache, int fd)
{
	t_list	*node;
	t_list	*new_node;

	if (*cache == NULL)
	{
		*cache = (t_list *)malloc(sizeof(t_list));
		(*cache)->fd = fd;
		return (*cache);
	}
	node = *cache;
	while (node->next)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	if (node->fd == fd)
		return (node);
	new_node = (t_list *)malloc(sizeof(t_list));
	new_node->fd = fd;
	node->next = new_node;
	new_node->prev = node;
	return (new_node);
}

char	*get_next_line(int fd)
{
	static t_list	*cache;
	char			buffer[BUFFER_SIZE + 1];
	char			*result;
	size_t			read_size;

	if (read(fd, buffer, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (find_node(&cache, fd)->value && ft_strchr(find_node(&cache, fd)->value, '\n'))
	{
		buffer[0] = '\0';
		ft_strlcat(buffer, find_node(&cache, fd)->value, ft_strlen(find_node(&cache, fd)->value) + 1);
		del_node(&cache, fd);
		make_new_line(&cache, buffer, &result, fd);
		return (result);
	}
	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = '\0';
		if (read_size < BUFFER_SIZE)
			return (low_read(&cache, buffer, fd));
		if (make_new_line(&cache, buffer, &result, fd) == 1)
			return (result);
	}
}

#include <fcntl.h>
#include <stdio.h>
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = NULL;
    for (int i = 0; i < 6; i++)
    {
		str = get_next_line(fd);
		printf("%s", str);
		if (str)
	    	free(str);
	}
}
