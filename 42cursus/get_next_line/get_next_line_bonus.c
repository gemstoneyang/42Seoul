/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:15:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/19 20:25:01 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_new_line_sub(char **cache, char buffer[], char *nxt_chr)
{
	char	*tmp;
	char	*result;

	tmp = ft_strndup(buffer, nxt_chr - buffer + 1);
	if (!tmp)
		return (NULL);
	result = ft_strjoin(*cache, tmp);
	free(tmp);
	if (!result)
		return (NULL);
	free(*cache);
	if (*(nxt_chr + 1) == '\0')
		*cache = NULL;
	else
	{
		*cache = ft_strndup(nxt_chr + 1, ft_strlen(nxt_chr + 1));
		if (!(*cache))
		{
			free(result);
			return (NULL);
		}
	}
	return (result);
}

int	make_new_line(char **cache, char buffer[], char **result)
{
	char	*tmp;

	if (*cache == NULL)
	{
		*cache = ft_strndup("", 0);
		if (!*cache)
		{
			*result = NULL;
			return (1);
		}
	}
	if (ft_strchr(buffer, '\n') == NULL)
	{
		tmp = *cache;
		*cache = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!(*cache))
		{
			*result = NULL;
			return (1);
		}
		return (0);
	}
	*result = make_new_line_sub(cache, buffer, ft_strchr(buffer, '\n'));
	return (1);
}

char	*low_read(char **cache, char buffer[])
{
	char	*result;

	if (ft_strlen(buffer) == 0)
	{
		if (*cache == NULL)
			return (NULL);
		result = ft_strndup(*cache, ft_strlen(*cache));
		if (!result)
			return (NULL);
		free(*cache);
		*cache = NULL;
		return (result);
	}
	if (make_new_line(cache, buffer, &result) == 0)
	{
		result = *cache;
		*cache = NULL;
		return (result);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*cache[10240];
	char		buffer[BUFFER_SIZE + 1];
	char		*result;
	size_t		read_size;

	if (read(fd, buffer, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (cache[fd] && ft_strchr(cache[fd], '\n'))
	{
		buffer[0] = '\0';
		ft_strlcat(buffer, cache[fd], ft_strlen(cache[fd]) + 1);
		free(cache[fd]);
		cache[fd] = NULL;
		make_new_line(&(cache[fd]), buffer, &result);
		return (result);
	}
	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		buffer[read_size] = '\0';
		if (read_size < BUFFER_SIZE)
			return (low_read(&(cache[fd]), buffer));
		if (make_new_line(&(cache[fd]), buffer, &result) == 1)
			return (result);
	}
}
