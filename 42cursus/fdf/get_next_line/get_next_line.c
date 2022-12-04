/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:13:22 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 13:03:04 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	ft_read_file(int fd, char **cache)
{
	char	*buffer;
	ssize_t	read_byte;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ERROR);
	read_byte = 1;
	while (!gnl_strchr(*cache, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (ERROR);
		}
		buffer[read_byte] = '\0';
		*cache = gnl_strjoin(*cache, buffer);
		if (*cache == NULL)
		{
			free(buffer);
			return (ERROR);
		}
	}
	free(buffer);
	return (SUCCESS);
}

static ssize_t	ft_get_line(char **result, char *cache)
{
	int		i;

	i = 0;
	if (!cache[i])
	{
		*result = NULL;
		return (SUCCESS);
	}
	while (cache[i] && cache[i] != '\n')
		i++;
	*result = (char *)malloc((i + 1) * sizeof(char));
	if (*result == NULL)
		return (ERROR);
	i = 0;
	while (cache[i] && cache[i] != '\n')
	{
		(*result)[i] = cache[i];
		i++;
	}
	(*result)[i] = '\0';
	return (SUCCESS);
}

static ssize_t	ft_update_cache(char **cache)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while ((*cache)[i] && (*cache)[i] != '\n')
		i++;
	if (!(*cache)[i] || !(*cache)[i + 1])
	{
		free(*cache);
		*cache = NULL;
		return (SUCCESS);
	}
	str = (char *)malloc((gnl_strlen(*cache) - i + 1) * sizeof(char));
	if (!str)
		return (ERROR);
	i++;
	j = 0;
	while ((*cache)[i])
		str[j++] = (*cache)[i++];
	str[j] = '\0';
	free(*cache);
	*cache = str;
	return (SUCCESS);
}

ssize_t	get_next_line(char **result, int fd)
{
	static char	*cache;

	*result = NULL;
	if (read(fd, NULL, 0) == ERROR || BUFFER_SIZE < 1)
		return (gnl_free_all(cache, *result));
	if (ft_read_file(fd, &cache) == ERROR)
		return (gnl_free_all(cache, *result));
	if (ft_get_line(result, cache) == ERROR)
		return (gnl_free_all(cache, *result));
	if (ft_update_cache(&cache) == ERROR)
		return (gnl_free_all(cache, *result));
	return (SUCCESS);
}
